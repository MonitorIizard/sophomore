public class Example1 {
    public static void main( String[] args ) {
        int var1 = 5, var2 = 5;
        A obj = new A();
        System.out.println( var1 + " " + var2 );
    }
}

class A {
    int x = 10, y = 5;
    void methodA( int a, int b ) {
        a = x;
        b = y;
    }
}
