import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;

public class Main extends JPanel implements ActionListener, KeyListener, MouseMotionListener {

    private class Particle {
        double currentX, currentY;
        double targetX, targetY;
        double baseTargetX, baseTargetY;

        Particle(double baseX, double baseY, double startX, double startY) {
            this.baseTargetX = baseX;
            this.baseTargetY = baseY;
            this.targetX = baseX;
            this.targetY = baseY;
            this.currentX = startX;
            this.currentY = startY;
        }
    }

    private double hue = 0.0;
    private int cx = 400;
    private double rotationAngle = 0.0;
    private int cy = 300; // مركز القلب على المحور الصادي
    private int mouseX = -1000; // إحداثيات الماوس المبدئية (خارج الشاشة)
    private int mouseY = -1000;
    private Timer timer;
    private ArrayList<Particle> particles;

    public Main() {
        this.setPreferredSize(new Dimension(800, 600));
        this.setBackground(Color.BLACK);
        this.setFocusable(true); // مهم جداً لاستقبال أوامر الكيبورد
        this.addKeyListener(this);
        this.addMouseMotionListener(this); // تفعيل استقبال حركة الماوس

        particles = new ArrayList<>();
        double scale = 15.0; // مقياس التكبير للقلب

        // معادلة القلب الرياضية لرسم الحواف (قلب مفرغ)
        // قمنا بتصغير الخطوة أكثر (0.003) لزيادة كثافة الحبيبات
        for (double t = 0; t <= Math.PI * 2; t += 0.003) {
            double targetX = 16 * Math.pow(Math.sin(t), 3);
            double targetY = -(13 * Math.cos(t) - 5 * Math.cos(2 * t) - 2 * Math.cos(3 * t) - Math.cos(4 * t));

            // إضافة تبعثر عشوائي للأهداف لجعل القلب "عريضاً" وليس خطاً واحداً
            double offsetX = (Math.random() - 0.5) * 35; // عرض الخط
            double offsetY = (Math.random() - 0.5) * 35;

            // تعيين مواقع ابتدائية عشوائية مبعثرة
            double startX = (Math.random() - 0.5) * 1200;
            double startY = (Math.random() - 0.5) * 1000;

            particles.add(new Particle(targetX * scale + offsetX, targetY * scale + offsetY, startX, startY));
        }

        // مؤقت (Timer) لتحديث الشاشة كل 30 جزء من الثانية
        timer = new Timer(30, this);
        timer.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        // تفعيل التنعيم (Antialiasing) لرسم أكثر دقة ووضوح
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        // توليد لون جديد بناءً على تدرج الطيف (hue)
        Color color = Color.getHSBColor((float) hue, 1.0f, 1.0f);
        g2d.setColor(color);

        // رسم الحبيبات
        for (Particle p : particles) {
            int drawX = cx + (int) p.currentX;
            int drawY = cy + (int) p.currentY;
            // رسم كل حبيبة كدائرة صغيرة جداً
            g2d.fillOval(drawX, drawY, 2, 2);
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        hue += 0.005; // تغيير درجة اللون ببطء
        if (hue > 1.0) {
            hue = 0.0;
        }

        // دوران القلب بشكل ثلاثي الأبعاد (أفقي) بحيث لا يتحرك للأعلى أو الأسفل
        rotationAngle += 0.02; // سرعة الدوران المستمر

        // تحديث مواقع الحبيبات لتقترب تدريجياً من الهدف لتشكيل القلب
        for (Particle p : particles) {
            // الدوران الأفقي: نغير الإحداثي السيني (X) فقط لعمل تأثير 3D
            p.targetX = p.baseTargetX * Math.cos(rotationAngle);
            p.targetY = p.baseTargetY; // الإحداثي الصادي يبقى ثابتاً (لا فوق ولا تحت)

            // الانجذاب نحو الهدف الأساسي (التجمع) مع تسريع بسيط
            p.currentX += (p.targetX - p.currentX) * 0.05;
            p.currentY += (p.targetY - p.currentY) * 0.05;

            // التفاعل مع الماوس (تنافر/إبعاد الحبيبات عند اقتراب الماوس)
            double actualX = cx + p.currentX;
            double actualY = cy + p.currentY;
            double dx = actualX - mouseX;
            double dy = actualY - mouseY;
            double dist = Math.sqrt(dx * dx + dy * dy);

            if (dist < 100 && dist > 0) { // دائرة التأثر بالماوس (نصف قطرها 100 بكسل)
                double force = (100 - dist) / 100.0;
                p.currentX += (dx / dist) * force * 30; // قوة التنافر والدفع
                p.currentY += (dy / dist) * force * 30;
            }
        }

        repaint(); // تحديث الرسم ليعكس اللون الجديد والتحركات
    }

    // --- أوامر التحكم لتحريك القلب باستخدام الأسهم ---
    @Override
    public void keyPressed(KeyEvent e) {
        int speed = 15; // سرعة تحرك القلب
        int key = e.getKeyCode();
        if (key == KeyEvent.VK_LEFT) {
            cx -= speed;
        } else if (key == KeyEvent.VK_RIGHT) {
            cx += speed;
        } else if (key == KeyEvent.VK_UP) {
            cy -= speed;
        } else if (key == KeyEvent.VK_DOWN) {
            cy += speed;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
    }

    @Override
    public void keyTyped(KeyEvent e) {
    }

    // --- أحداث الماوس ---
    @Override
    public void mouseDragged(MouseEvent e) {
        mouseX = e.getX();
        mouseY = e.getY();
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        mouseX = e.getX();
        mouseY = e.getY();
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Moving Heart Particles");
        Main heartPanel = new Main();
        frame.add(heartPanel);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null); // وضع النافذة في منتصف الشاشة
        frame.setVisible(true);
    }
}
