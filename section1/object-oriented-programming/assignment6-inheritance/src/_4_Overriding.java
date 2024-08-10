public class _4_Overriding {


}

class SuperClass {
    private int num = 1;

    private int getNumber() {
        return num;
    }
}

class Subclass extends SuperClass {
    private int num = 10;
//    protected int getNumbers() {
//        return num+5;
//    }
//    @Override
    public int getNumber() {
            return num+5;
    }

//    protected int getNumber() {
//            return num+5;
//    }

//    public int getNumber() {
//        return num+5;
//    }

//    protected int getNumber( int num ) {
//        return num+5;
//    }
//    int getNumber() {
//        return num+5;
//    }

//    private int getNumber() {
//        return num+5;
//    }

    public static void main( String[] args ) {
        Subclass s = new Subclass();
        System.out.println( s.getNumber() );
    }
}
