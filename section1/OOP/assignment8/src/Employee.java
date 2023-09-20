class _4_Employee {
}


public abstract class Employee {
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
}

