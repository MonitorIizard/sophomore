public class _1_Output {
}

class A_1 {
    void f() {
        System.out.println("A");
    }
    int x = 1;
    void inc() {
        System.out.println("in class a");
        x++;
    }
    int get() { return x; }
}

class B_1 extends  A_1 {

    int x = 2;
    void inc() {
//        System.out.println("in class b");
        x++;
    }
    int get() { return x ;}
    void f() {
        System.out.println("B");
    }
}

class _1_Test {
    static void t(A_1 a) {
        a.f();
    }
    public static void main( String[] args ) {
        t(new A_1());
        t(new B_1());
    }
}

class _2_Test {
    public static void main( String[] args ) {
        B_1 b = new B_1();
        A_1 a = b;
        a.inc();
        b.inc();
        System.out.println(a.x+","+b.x);
        System.out.println(a.get()+","+b.get());
    }
}

class _3_Test {
    public static void main( String[] args ) {
//        Object fruit = new Fruit();
//        Object apple = new (Apple)fruit;
        int a = 5;
        int x = a;
        a++;
        System.out.println(a);
    }
}



