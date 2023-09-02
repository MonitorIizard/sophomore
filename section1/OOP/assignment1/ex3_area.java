import java.util.ArrayList;
import java.util.Scanner;

public class ex3_area {
    public static void main(String[] args) {
        System.out.println("Enter three points for a triangle : ");

        ArrayList<ArrayList<Float>> coordinates = new ArrayList<ArrayList<Float>>();

        for (int i = 0; i < 3; i++) {
            ArrayList<Float> points = new ArrayList<Float>();
            for (int j = 0; j < 2; j++) {
                Scanner value = new Scanner(System.in);
                points.add(value.nextFloat());
            }
            coordinates.add(points);
        }

        float side1 = (float) Math.sqrt(
                Math.pow(coordinates.get(0).get(0) - coordinates.get(1).get(0), 2)
                        + Math.pow(coordinates.get(0).get(1) - coordinates.get(1).get(1), 2)
        );
        float side2 = (float) Math.sqrt(
                Math.pow(coordinates.get(0).get(0) - coordinates.get(2).get(0), 2)
                        + Math.pow(coordinates.get(0).get(1) - coordinates.get(2).get(1), 2)
        );
        float side3 = (float) Math.sqrt(
                Math.pow(coordinates.get(1).get(0) - coordinates.get(2).get(0), 2)
                        + Math.pow(coordinates.get(1).get(1) - coordinates.get(2).get(1), 2)
        );

        float s = (side1 + side2 + side3) / 2;
        float area = (float) Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));

        System.out.println(area);

    }
}
