#include <iostream>
#include <vector>

using namespace std;

struct Student
{
    string name;
    vector<int> grades;
};

float average(vector<int> grades)
{
    float result = 0;
    for (int grade : grades)
    {
        result += grade;
    }
    return result / 5;
}

int main()
{
    vector<Student> students;

    for (int i = 0; i < 2; i++)
    {
        Student s;
        cout << "Enter student name: ";
        cin >> s.name;
        cout << "Enter student grade: ";

        for (int i = 0; i < 5; i++)
        {
            int grade;
            cin >> grade;

            s.grades.push_back(grade);
        }

        students.push_back(s);
    }

    for (const Student &student : students)
    {
        cout << student.name << ": ";

        cout << average(student.grades) << " ";

        cout << endl;
    }
}