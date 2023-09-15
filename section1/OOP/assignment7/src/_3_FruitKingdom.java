public class _3_FruitKingdom {
    public static void main( String[] args ) {
        Fruit fruit = new GoldenDelicious();
        Orange orange = new Orange();

        orange.MakeOrangeJuice();

    }
}

class Fruit {


}
class Apple extends Fruit {
    public void MakeApple() {
        System.out.println("makeApple");
    }
}

class Orange extends Fruit {
    public void MakeOrangeJuice() {
        System.out.println("makeOrangeJuice");
    }
}

class GoldenDelicious extends Apple {

}

class Mcintouch extends Apple {

}