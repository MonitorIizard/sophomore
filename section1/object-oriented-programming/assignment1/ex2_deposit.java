import java.util.Scanner;

public class ex2_deposit {
    public static void main(String[] args) {
        System.out.println("Enter the montly saving amount :");
        Scanner deposit = new Scanner(System.in);
        float n = deposit.nextFloat();
        float total = 0;
        double interestRate = 5.0;
        double interest = 1 + (interestRate / 12.0) / 100;
        int period = 6;


        for (int i = 0; i < period; i++) {
            total += n;
            total *= interest;
        }

        System.out.println(String.format("After the sixth month, the account value is : %f", total));
    }
}
