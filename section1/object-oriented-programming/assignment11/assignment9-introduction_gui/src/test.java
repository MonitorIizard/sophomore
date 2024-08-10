public class test {
    public static void main( String[] args ) {
        SuperClass o = new SubClass("Three Man Down", "จำฉันได้ไหม");
        System.out.println(((SubClass)o).artist);
    }
}

class SuperClass {
    public String artist = "Artist";
    public String music = "music";
    public SuperClass( String a, String m ) {
        this.artist = a;
        this.music = m;
    }
}

class SubClass extends SuperClass {
    public SubClass(String a, String m) {
        super(a, m);
    }
}