#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class Person
{
protected:
    int id_;
    string name_;
    int age_;

public:
    Person()
    {
        id_ = -1;
        name_ = "Unknown";
        age_ = -1;
    }
    Person(int id, string name, int age) : id_(id), name_(name), age_(age) {}

    virtual ~Person() = default;
    virtual void work() = 0;
    virtual void printInfo() = 0;

    int getId()
    {
        return id_;
    }
    string getName()
    {
        return name_;
    }
    int getAge()
    {
        return age_;
    }

    void setId(int set_id)
    {
        id_ = set_id;
    }

    void setName(string set_name)
    {
        name_ = set_name;
    }

    void setAge(int set_age)
    {
        age_ = set_age;
    }
};

class Student : public Person
{
private:
    vector<double> grades_;

public:
    Student() {}
    Student(int id, string name, int age, vector<double> grades) : Person(id, name, age), grades_(grades) {}
    void addGrade(int _add_grade)
    {
        grades_.push_back(_add_grade);
    }

    double getAverage()
    {
        if (grades_.size() == 0)
            return -1;
        double sum = 0.00;
        for (const auto &grade : grades_)
        {
            sum += grade;
        }

        return sum / grades_.size();
    }

    double getHighestGrade()
    {
        if (grades_.size() == 0)
            return -1;
        double _highest = grades_[0];
        for (const auto &grade : grades_)
        {
            if (grade > _highest)
                _highest = grade;
        }

        return _highest;
    }

    double getLowestGrade()
    {
        if (grades_.size() == 0)
            return -1;
        double _lowest = grades_[0];
        for (const auto &grade : grades_)
        {
            if (grade < _lowest)
                _lowest = grade;
        }

        return _lowest;
    }

    void work()
    {
        cout << name_ << " is Studying.\n";
    }

    void printInfo()
    {
        cout << "ID: " << id_ << endl;
        cout << "Name: " << name_ << endl;
        cout << "Age: " << age_ << endl;
        cout << "Average: " << getAverage() << endl;
        cout << "Highest: " << getHighestGrade() << endl;
        cout << "Lowest: " << getLowestGrade() << endl;
    }
};

class Professor : public Person
{
private:
    string department_;
    double salary_;

public:
    Professor() {}
    Professor(int id, string name, int age, string department, double salary) : Person(id, name, age), department_(department), salary_(salary) {}
    void teachCource(string course_name)
    {
        cout << name_ << "is teaching " << course_name << endl;
    }
    void raiseSalary(double percentage)
    {
        salary_ += (percentage * salary_);
    }

    void work()
    {
        cout << name_ << " is Teaching.\n";
    }

    void printInfo()
    {
        cout << "ID: " << id_ << endl;
        cout << "Name: " << name_ << endl;
        cout << "Age: " << age_ << endl;
        cout << "Department: " << department_ << endl;
        cout << "Salary: " << salary_ << endl;
    }
};

class Staff : public Person
{
private:
    string position_;

public:
    Staff() {}
    Staff(int id, string name, int age, string position) : Person(id, name, age), position_(position) {}

    void work()
    {
        cout << name_ << " is managing university operations.\n";
    }

    void manageOffice(string office)
    {
        cout << name_ << " is managing " << office << endl;
    }
    void printInfo()
    {
        cout << "ID: " << id_ << endl;
        cout << "Name: " << name_ << endl;
        cout << "Age: " << age_ << endl;
        cout << "Position: " << position_ << endl;
    }
};

class University
{
private:
    vector<Person *> people_;

public:
    void addPerson(Person *person)
    {
        people_.push_back(person);
    }

    Person *getPerson(const string &name) const
    {
        auto it = find_if(people_.begin(), people_.end(), [&](Person *p)
                          { return p->getName() == name; });
        if (it != people_.end())
            return *it;
        else
            return nullptr;
    }

    void removePerson(const string &name)
    {
        auto it = find_if(people_.begin(), people_.end(), [&](Person *p)
                          { return p->getName() == name; });
        if (it != people_.end())
        {
            delete *it;
            people_.erase(it);
        }
    }

    void printInfo(const string &name)
    {
        Person *p = getPerson(name);

        if (p)
            p->printInfo();
        else
            cout << "Not found.\n";
    }

    void displayAll() const
    {
        for (Person *p : people_)
        {
            p->printInfo();
            cout << "---\n";
        }
    }

    void workAll() const
    {
        for (Person *p : people_)
            p->work();
    }

    ~University()
    {
        for (Person *p : people_)
            delete p;
    }
};

int main()
{
    University uni;
    int choice;

    do
    {
        cout << "\n===== University Management =====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Professor\n";
        cout << "3. Add Staff\n";
        cout << "4. Display All\n";
        cout << "5. Search by Name\n";
        cout << "6. Remove by Name\n";
        cout << "7. Show All Working\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, age, numGrades;
            string name;
            cout << "ID: ";
            cin >> id;
            cout << "Name: ";
            cin >> name;
            cout << "Age: ";
            cin >> age;
            cout << "Number of grades: ";
            cin >> numGrades;
            vector<double> grades;
            for (int i = 0; i < numGrades; i++)
            {
                double g;
                cout << "  Grade " << i + 1 << ": ";
                cin >> g;
                grades.push_back(g);
            }
            uni.addPerson(new Student(id, name, age, grades));
            cout << "Student added.\n";
        }
        else if (choice == 2)
        {
            int id, age;
            string name, department;
            double salary;
            cout << "ID: ";
            cin >> id;
            cout << "Name: ";
            cin >> name;
            cout << "Age: ";
            cin >> age;
            cout << "Department: ";
            cin >> department;
            cout << "Salary: ";
            cin >> salary;
            uni.addPerson(new Professor(id, name, age, department, salary));
            cout << "Professor added.\n";
        }
        else if (choice == 3)
        {
            int id, age;
            string name, position;
            cout << "ID: ";
            cin >> id;
            cout << "Name: ";
            cin >> name;
            cout << "Age: ";
            cin >> age;
            cout << "Position: ";
            cin >> position;
            uni.addPerson(new Staff(id, name, age, position));
            cout << "Staff added.\n";
        }
        else if (choice == 4)
        {
            uni.displayAll();
        }
        else if (choice == 5)
        {
            string name;
            cout << "Enter name: ";
            cin >> name;
            uni.printInfo(name);
        }
        else if (choice == 6)
        {
            string name;
            cout << "Enter name: ";
            cin >> name;
            uni.removePerson(name);
            cout << "Removed.\n";
        }
        else if (choice == 7)
        {
            uni.workAll();
        }
    } while (choice != 0);

    return 0;
}