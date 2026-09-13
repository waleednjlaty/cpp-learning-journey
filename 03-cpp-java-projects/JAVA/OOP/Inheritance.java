public class Inheritance {

    public static void main(String[] args) {
        Student student = new Student(100, 19, "Waleed");
        Employ employ = new Employ(400, "Ahmed", 20);
        System.out.println("//=======================================================//");
        student.printStudentinfo();
        System.out.println("//=======================================================//");
        employ.printEmploySalary();
        System.out.println("//=======================================================//");
    }
}

class Person {
    int age;
    String name;

    Person(int a, String n) {
        this.name = n;
        this.age = a;
    }

    void printinfo() {
        System.out.println("Your Name is : " + name);
        System.out.println("Your Age is : " + age);
    }
}

class Student extends Person {
    int grade;

    Student(int g, int ag, String na) {
        super(ag, na);
        this.grade = g;

    }

    void printStudentinfo() {
        printinfo();
        System.out.println("Your Grade is : " + grade);
    }
}

class Employ extends Person {
    int salary;

    Employ(int s, String n, int agea) {
        super(agea, n);
        this.salary = s;
    }

    void printEmploySalary() {
        printinfo();
        System.out.println("Your Salary is :" + salary);
    }
}