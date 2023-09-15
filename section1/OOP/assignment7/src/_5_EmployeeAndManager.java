public class _5_EmployeeAndManager {
}

class Employee {
    protected int id;
    protected String name;
    protected double salary;
    protected Address address;
    Employee() {

    }

    public String getDetails() { return " s"; }
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

    public String getStreet() { return this.street; }
    public String getCity() { return this.city; }
    public void setStreet( String street ) { this.street = street; }
    public void setCity( String city ) { this.city = city; }

    public String getAddressInfo() { return String.format("street: %s, city: %s", this.street, this.city ); }
}

class Manager extends Employee {
    protected String parkingNo;

    public String getParkingNo() { return this.parkingNo; }
    public void setParkingNo(String parkingNo) { this.parkingNo = parkingNo; }
    public String getDetails() { return "s"; }
}