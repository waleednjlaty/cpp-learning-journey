public class newApp {
    public static void main(String[] args) {
        Square square = new Square(5, 7);
        Rectangle rectangle = new Rectangle(5, 9);
        square.squarePrint();
        circle.circlePrint();
    }
}

class Shape {
    int lingth, width;

    Shape(int a, int b) {
        this.lingth = a;
        this.width = b;
    }

    int hit() {
        return 0;
    }
}

class Square extends Shape {
    Square(int xa, int yb) {
        super(xa, yb);
    }

    @Override
    int squarespace() {

        return lingth * width;
    }

    void squarePrint() {

        System.out.println("the area of Rectangle :" + squarespace());
    }
}

class circle extends Shape {

    circle(int reduse) {

    }

    @Override
    float circlespace() {

        return 3.14 * reduse * reduse;
    }

    void circlelePrint() {
        System.out.println("the area of Rectangle :" + circlespace);
    }
}