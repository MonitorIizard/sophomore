public class _5_EmployeeAndManager {
    public static void main( String[] args ) {
        Employee emp = new Manager( 1, "Mok Maard", 20000, new Address("Viphavadee Rangsit", "Bangkok" ), "15" );
        System.out.println( emp.getDetails() );
    }
}

class Employee {
    protected int id;
    protected String name;
    protected double salary;
    protected Address address;
    Employee() {

    }

    public String getDetails() {
        return String.format(
                """
                Employee, id : %d name : %s, salary: %f
                Address, street : %s, city : %s
                """, this.id, this.name, this.salary, this.address.getCity(), this.address.getCity() );
    }
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }
    public String getName() { return name; }
    public void setName( String name ) { this.name = name; }
    public double getSalary() { return this.salary; }
    public void setSalary( double salary ) { this.salary = salary; }
    public Address getAddress( ) { return address; }
    public void setAddress( Address address ) { this.address = address;  }

}

class Address {
    protected String street;
    protected String city;

    Address( String street, String city) {
        this.street = street;
        this.city = city;
    }

    public String getStreet() { return this.street; }
    public String getCity() { return this.city; }
    public void setStreet( String street ) { this.street = street; }
    public void setCity( String city ) { this.city = city; }

    public String getAddressInfo() { return String.format("street: %s, city: %s", this.street, this.city ); }
}

class Manager extends Employee {
    protected String parkingNo;

    Manager( int id, String name, double salary, Address address, String parkingNo ) {
        this.id = id;
        this.name = name;
        this.salary = salary;
        this.address = address;
        this.parkingNo = parkingNo;
    }
    public String getParkingNo() { return this.parkingNo; }
    public void setParkingNo(String parkingNo) { this.parkingNo = parkingNo; }
    public String getDetails() {
        return String.format("""
                Manager, id : %d name : %s, salary: %f
                Address, street : %s, city : %s
                Parking No. %s""", this.id, this.name, this.salary, this.address.getStreet(), this.address.getCity(), this.parkingNo );

    }
}