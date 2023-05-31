#include <iostream>
using std :: string;

class AbstractEmployee {
    virtual void AskForPromotion () = 0;
};

class Employee: AbstractEmployee {
protected:
    string Name;
    string Company;
    int Age;

public:
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        Age = age;
    }
    int getAge() {
        return Age;
    }

    void IntroduceYourself() {
        std :: cout << "Name - " << Name << std :: endl;
        std :: cout << "Company - " << Company << std :: endl;
        std :: cout << "Age - " << Age << std :: endl;
    }
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion() {
        if (Age > 30)
            std :: cout << Name << "Got promoted!" << std :: endl;
        else 
            std :: cout << Name << ", sorry no promotion for you!" << std :: endl;
    }
};

class Developer : public Employee {
public:
    string favouriteProgrammingLanguage;
    Developer(string name, string company, int age, string FavouriteProgrammingLanguage) 
        :Employee(name, company, age)
    {
        favouriteProgrammingLanguage = FavouriteProgrammingLanguage;
    }

    void FixBug() {
        std :: cout << Name << " fixed bug using " << favouriteProgrammingLanguage << std :: endl;
    }
};

class Teacher : public Employee {
public:
    string Subject;
    void PrepareLesson () {
        std :: cout << Name << " is preparing " << Subject << " lesson " << std :: endl;
    }

    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age) {
            Subject = subject;
    }
};

int main () {
    Employee employee1 = Employee("Mok", "GoodGeek", 19);
    // employee1.Name = "MOK";
    // employee1.Company = "GoodGeek";
    // employee1.Age = 19;
    //employee1.IntroduceYourself();

    // Employee employee2;
    // employee2.Name = "John";
    // employee2.Company = "GG";
    // emoloyee2.Age = 25;
    // employee2.IntroduceYourself();

    //employee1.AskForPromotion();

    Developer dev1 = Developer("Mok", "Facebook", 25, "js");
    dev1.FixBug();

    Teacher T = Teacher("Jack", "scoohl", 38, "Science");
    T.PrepareLesson();
    T.AskForPromotion();

    return 0;
}