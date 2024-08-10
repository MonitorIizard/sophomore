import java.util.ArrayList;

public class _5_Employee {
    public static void main( String[] args ) {
        ArrayList< Employee > arrayEarn = new ArrayList<>( );
        arrayEarn.add( new Employee( "Mok", "Maard", "112", 500));
        arrayEarn.add( new Employee( "Athica", "Leksansueng", "118", 590));

        printEmp( arrayEarn );
    }

    static void printEmp( ArrayList< Employee > array ) {
        for( Employee i : array ) {
            System.out.printf("%s %s %f %f\n", i.getFirstname(), i.getLastname(), i.earning(), i.bonus(5));
        }
    }
}

class Employee {
    private String firstname;
    private String lastname;
    private String id;
    private double salary;

    Employee(String firstname, String lastname, String id, double salary) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.id = id;
        this.salary = salary;
    }

    double earning() {
        return salary * 95 / 100;
    }

    double bonus( int year ) {
        if( year > 5 ) return salary * 12;
        return  salary * 6;
    }

    String getFirstname() {
        return firstname;
    }

    String getLastname() {
        return lastname;
    }

}
