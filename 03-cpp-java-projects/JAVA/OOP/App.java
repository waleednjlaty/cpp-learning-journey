public class App {
    public static void main(String[] args) {

        Gun Gun = new Gun(30);
        Gun.fire();
        Gun.Reload();
        System.out.println("==============================");
        RPG Rpg = new RPG(1);
        Rpg.fire();
        Rpg.Reload();
    }
}

abstract class weapon {
    int r;

    weapon(int rr) {
        this.r = rr;
    }

    abstract int getBullet();

    abstract void Reload();

    abstract void fire();

}

class Gun extends weapon {
    Gun(int r) {
        super(r);
    }

    int getBullet() {
        return r;
    }

    void Reload() {
        System.out.println("You are Reload the Gun");
        r += 30;
        System.out.println("The Gun now has " + r + " bullets");

    }

    void fire() {
        System.out.println("You are Fire on Gun");
        r -= 1;
        System.out.println("GUN's Bullets now : " + getBullet());
    }

}

class RPG extends weapon {
    RPG(int r) {
        super(r);
    }

    int getBullet() {
        return r;
    }

    void Reload() {
        System.out.println("You are Reload the RPG");
        r += 1;
        System.out.println("The RPG now has " + r + " bullets");

    }

    void fire() {
        System.out.println("You are Fire on Gun");
        r -= 1;
        System.out.println("GUN's Bullets : " + getBullet());

    }
}