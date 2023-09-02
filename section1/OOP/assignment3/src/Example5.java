import java.util.Scanner;

public class Example5 {
    public static void main ( String[] args ) {
        Scanner sc = new Scanner( System.in );
        RoachPopulation obj = new RoachPopulation( sc.nextInt() );

        int i = 0;
        int loop = sc.nextInt();

        while( i < loop ) {
            obj.waitR();
            obj.spray();
            i++;
        }

        System.out.println( obj.getPopulation() );
    }
}

class RoachPopulation {
    private int population;
    RoachPopulation( int population ) {
        this.population = population;
    }

    public void setPopulation( int population ) {
        this.population = population;
    }
    public void waitR() {
        this.population *= 2;
    }

    public void spray() {
        this.population = (int) Math.ceil( this.population * ( 90.0 / 100 ));
    }

    public int getPopulation() {
        return this.population;
    }
}
