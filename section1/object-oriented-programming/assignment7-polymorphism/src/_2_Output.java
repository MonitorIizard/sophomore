public class _2_Output {
}

class Test1 {
    public static void main( String[] args ) {
        Object a1 = new A();
        Object a2 = new Object();
        System.out.println(a1);
        System.out.println(a2);
    }
}

class A {
    int x;
    public boolean equals(A a) {
        System.out.println(this.x);
        System.out.println(a.x);
        return this.x == a.x;
    }

    public String toString() {
        return "A's x is " + x;
    }
}

class Test2 {
    public static void main( String[] args ) {
        Object a1 = new A();
        Object a2 = new A();
        System.out.println(a1.equals(a2));
    }
}

class Test3 {
    public static void main( String[] args ) {
        A a1 = new A();
        A a2 = new A();
        System.out.println(a1.equals(a2));
    }
}

