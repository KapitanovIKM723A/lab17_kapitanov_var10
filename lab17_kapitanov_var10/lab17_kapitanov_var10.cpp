#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Person {
protected:
    char* name;
    int age;
    double weight;
public:
    Person(const char* name = "", int age = 0, double weight = 0.0) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
        this->age = age;
        this->weight = weight;
    }

    virtual ~Person() {
        delete[] name;
    }

    virtual void print() const {
        cout << "Name: " << name << ", Weight: " << weight << ", Age: " << age;
    }

    void setAge(int newAge) {
        age = newAge;
    }
};

class Adult : public Person {
private:
    int passportNumber;
public:
    Adult(const char* name = "", int age = 0, double weight = 0.0, int passportNumber = 0)
        : Person(name, age, weight), passportNumber(passportNumber) {}

    void print() const override {
        Person::print();
        cout << ", Passport Number: " << passportNumber;
    }

    void setPassportNumber(int newPassportNumber) {
        passportNumber = newPassportNumber;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    Person person("Ivan", 25, 70.5);
    Adult adult("Petro", 30, 80.0, 123456);

    person.print();
    cout << " | ";
    adult.print();
    cout << endl;

    person.setAge(26);
    adult.setAge(31);
    adult.setPassportNumber(654321);

    person.print();
    cout << " | ";
    adult.print();
    cout << endl;

    return 0;
}