#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student{
public:
    Student(string name, int age) : Name(name), Age(age) {}

    void setAge(int a) { Age = a; }
    void setName(string n) { Name = n; }

    int getAge() const { return Age; }
    string getName() const { return Name; }

    void printStudentInfo() const {
        cout << "Name: " << Name << ", Age: " << Age << endl;
    }
private:
    string Name;
    int Age;
};


int main ()
{
    int selection = 0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:{
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            string name;
            int age;
            cout<< "Give student name: ";
            cin>> name;
            cout<<"Give student age: ";
            cin>> age;
            studentList.emplace_back(name, age);
            cout << "Student added to list.\n";
            break;
        }
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            if (studentList.empty()) {
                cout << "No students in the list.\n";
            } else {
                cout << "Students:\n";
                for (const auto& student : studentList) {
                    student.printStudentInfo();
                }
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            if (studentList.empty()) {
                cout << "No students in the list.\n";
                break;
            }

            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.getName() < b.getName();
                 });

            cout << "Students sorted by name:\n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            if (studentList.empty()) {
                cout << "No students in the list.\n";
                break;
            }

            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.getAge() < b.getAge();
                 });

            cout << "Students sorted by age:\n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;
        case 4:{
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            if (studentList.empty()) {
                cout << "No students in the list.\n";
                break;
            }

            string searchName;
            cout << "Give name for student search: ";
            cin>> searchName;

            auto it = find_if(studentList.begin(), studentList.end(),
                              [&searchName](const Student& s) {
                                  return s.getName() == searchName;
                              });

            if (it != studentList.end()) {
                cout << "Student found:\n";
                it->printStudentInfo();
            } else {
                cout << "Student not found.\n";
            }
            break;
        }
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    } while(selection < 5);

return 0;

}
