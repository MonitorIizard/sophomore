public class _5_Account1 {
}

class Date {
    private int day, month, year;

    public Date() {

    }

    public Date( int day, int month, int year ) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }
}
class Account {
    private int id;
    private double balance;
    private double annualInterestRate;
    private Date dateCreated;

    Account() {}

    Account( int id, double balance ) {
        this.id = id;
        this.balance = balance;
    }

    public int getId() { return id; }

    public double getBalance() { return balance; }

    public double getAnnualInterestRate() { return annualInterestRate; }

    public Date getDateCreated() { return dateCreated; }

    public void setId( int id ) { this.id = id; }

    public void setBalance( double balance ) { this.balance = balance; }

    public void setAnnualInterestRate( double annualInterestRate ) { this.annualInterestRate = annualInterestRate; }

    public void setDateCreated( Date dateCreated ) { this.dateCreated = dateCreated; }

    public double getMonthlyInterestRate() { return annualInterestRate / 12.0; }

    public double getMonthlyInterest() { return balance * annualInterestRate / 100; }

    public void withdraw( double amount ) {
        if( amount > balance ) {
            System.out.println("balance is less than amount");
            return;
        }
        this.balance = this.balance - amount;
    }

    public void deposit( double amount ) { this.balance += amount; }

}

