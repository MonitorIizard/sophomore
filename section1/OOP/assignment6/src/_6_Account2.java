import jdk.jfr.Percentage;

import java.time.LocalDateTime;

public class _6_Account2 {
    public static void main( String[] args ) {
        SavingAccount acc1123 = new SavingAccount(1123, 20000, 4.5 / 100, new Date(1, 1, 1970));
        acc1123.getObjPerson().setName("Athicha");
        acc1123.getObjPerson().setSurname("Leksansern");
        acc1123.getObjPerson().setAge(20);
        acc1123.getObjPerson().setbDate(new Date(13, 10, 2003));
        acc1123.withdraw(2500);
        acc1123.deposit(3000);

        PersonAccount acc1100 = new PersonAccount(1100, 0, 4.5 / 100, new Date(1, 1, 1970));
        acc1123.transferMoney(acc1100, 5000);

        System.out.println(acc1123);
        System.out.println(acc1100);

        FixedAccount acc1124 = new FixedAccount(1124, 20000, 7, new Date(1, 1, 2023));
        acc1124.getObjPerson().setName("Mister1124");
        acc1124.getObjPerson().setSurname("Lalala");
        acc1124.getObjPerson().setbDate(new Date(4, 12, 2003));
        acc1124.withdraw(2500);
        acc1124.deposit(3000);
        acc1124.transferMoney(acc1100, 1200);

        System.out.println(acc1124);
    }
}

class Person {
    private String name;
    private String surname;
    private int age;
    private Date bDate;

    Person() {}

    Person( String firstname, String lastname ) {
        this.name = firstname;
        this.surname = lastname;

    }

    public String getName() { return name; }

    public String getSurname() { return surname; }

    public int getAge() { return age; }

    public Date getbDate() { return bDate; }

    public void setName( String name ) { this.name = name; }

    public void setSurname( String surname ) { this.surname = surname; }

    public void setAge( int age ) { this.age = age; }

    public void setbDate( Date bDate ) { this.bDate = bDate; }
}

class PersonAccount extends Account {

    private Person objPerson; // composition object

    PersonAccount( int id, double balance, double interest, Date date ) {
        setId( id );
        setBalance( balance );
        setAnnualInterestRate( interest );
        setDateCreated( date );
        objPerson = new Person();
    };

    PersonAccount() {}
    public void transferMoney( PersonAccount acc1, int amount ) {
        if ( getBalance() < amount ) {
            System.out.println("balance is less than amount");
            return;
        }

        acc1.setBalance( acc1.getBalance() + amount );
        setBalance(getBalance() - amount);
    }

    @Override
    public double getMonthlyInterest() {
        LocalDateTime nowLDT = LocalDateTime.now();
        Date now = new Date(nowLDT.getDayOfMonth(), nowLDT.getMonth().getValue(), nowLDT.getYear());
        Date dateCreated = getDateCreated();
        int difference = now.getMonth() - dateCreated.getMonth();

        return super.getBalance() * difference * getMonthlyInterestRate();
    }

    @Override
    public String toString() {
        int id = getId();
        double balance = getBalance();
        Date createdDate = getDateCreated();
        int day = createdDate.getDay();
        int month = createdDate.getMonth();
        int year = createdDate.getYear();
        String name = getObjPerson().getName();
        String surname = getObjPerson().getSurname();
        return String.format("id : %d, balance : %.2f, created date : %d/%d/%d name : %s %s", id, balance, day, month, year, name, surname);
    }

    public Person getObjPerson() { return  this.objPerson; }

    public void setObjPerson( Person objPerson ) { this.objPerson = objPerson; }
}

class SavingAccount extends PersonAccount{

    SavingAccount( int id, double balance, double interest, Date date ) {
        setId( id );
        setBalance( balance );
        setAnnualInterestRate( interest );
        setDateCreated( date );
        setObjPerson( new Person() );
    };

    @Override
    public void transferMoney(PersonAccount acc1, int amount ) {
        amount += 20;
        if ( getBalance() < amount ) {
            System.out.println("balance is less than amount");
            return;
        }

        acc1.setBalance( acc1.getBalance() + amount );
        setBalance(getBalance() - amount);
    }
}

class FixedAccount extends PersonAccount {
    FixedAccount( int id, double balance, double interest, Date date ) {
        setId( id );
        setBalance( balance );
        setAnnualInterestRate( interest );
        setDateCreated( date );
        setObjPerson( new Person() );
    };
    @Override
    public void transferMoney(PersonAccount acc1, int amount ) {
        System.out.println("you can't transfer from fix account");
    }
}