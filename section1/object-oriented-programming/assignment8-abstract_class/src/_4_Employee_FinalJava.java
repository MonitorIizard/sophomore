//public class _4_Employee {
//}


import java.util.ArrayList;

abstract class Employee {
    private String firstname;
    private String lastname;
    private String id;
    public Employee( String firstname, String lastname, String id ) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.id = id;
    }
    public abstract double earning();
    public abstract double bonus( int year );

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public String getFirstname() {
        return firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public void setId(String id) {
        this.id = id;
    }
}

class SalariedEmployee extends Employee {
    private double salary;
    public SalariedEmployee( String firstname, String lastname, String id, double salary) {
        super( firstname, lastname, id ); //!!!!!!1 super( fistnae);
        this.salary = salary;
    }

    public double bonus( int year ) {
        if ( year >= 5 ) {
            return salary * 12;
        } else  {
            return salary * 6;
        }
    }

    public double earning() {
        return salary * 95 / 100;
    }

    public double getSalary() {
        return salary;
    }
}

class ComEmployee extends Employee{
    private double grossSale;
    private double ComRate;
    public ComEmployee(String firstname,String lastname,String id, double sales, double percent) {
        super( firstname, lastname, id ); //!!!!!!1 super( fistnae);
        this.grossSale = sales;
        this.ComRate = percent;
    }

    @Override
    public double earning() {
        return grossSale * ComRate;
    }

    @Override
    public double bonus(int year) {
        if ( year >= 5 ) {
            return grossSale * 6;
        } else  {
            return grossSale * 3;
        }
    }
}

class _4_Employee_FinalJava {
    private static void printEmp(ArrayList<Employee> employees) {
        for (int i = 0; i < employees.size(); i++) {
            Employee employee = employees.get(i);

            System.out.println(employee.getFirstname() + " " + employee.getLastname() + " " + employee.earning() + " " + employee.bonus(i + 2));
        }
    }

    public static void main(String[] args) {
        ArrayList<Employee> storeComEmployee = new ArrayList<Employee>();
        ArrayList<SalariedEmployee> storeSalariedEmployee = new ArrayList<SalariedEmployee>();

        storeComEmployee.add(new ComEmployee("Mok", "Maard", "11", 5000, 10.0));
        storeComEmployee.add(new ComEmployee("Aticha", "Leksanseng", "12", 3000, 10.0));
        storeComEmployee.add(new ComEmployee("Peerasin", "SriSri", "13", 800, 10.0));
        storeComEmployee.add(new ComEmployee("Chetsada", "-", "15", 5000, 10.0));

        printEmp(storeComEmployee);
    }
}