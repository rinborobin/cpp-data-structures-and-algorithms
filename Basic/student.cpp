#include <iostream>
#include <vector>
using namespace std;

// Features
// Add student
// Add grade
// Calculate average
// Print report
// Find highest average
// Remove student

class Student
{
private:
    string name;
    vector<int> grades;

public:
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void addGrade(int grade)
    {
        grades.push_back(grade);
    }
    double getAverage() const
    {
        int sum = 0;

        for (int grade : grades)
        {
            sum += grade;
        }

        return (double)sum / grades.size();
    }
};

int main()
{
    Student s1, s2;

    s1.setName("PlokJok");
    s1.addGrade(67);
    s1.addGrade(56);
    s1.addGrade(78);
    s1.addGrade(78);
    s1.addGrade(34);

    s2.setName("KlebJeb");
    s2.addGrade(67);
    s2.addGrade(75);
    s2.addGrade(78);
    s2.addGrade(56);
    s2.addGrade(90);

    cout << "Student Name: " << s1.getName() << endl;
    cout << "Average     : " << s1.getAverage() << endl;
    cout << "Student Name: " << s2.getName() << endl;
    cout << "Average     : " << s2.getAverage() << endl;
}