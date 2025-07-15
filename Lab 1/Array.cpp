/*
id: 22010126
name: muni
group: G3
lab: Lab G1*/

#include <iostream>
#include <string>

using namespace std;

struct Student 
{
    int id;
    string name;
    string contact;
    string email;
};

int main() 
{
    Student students[5];

    cout << "Enter details for student:\n";
    for (int i = 0; i < 5; i++) 
    {
        cout << "\nStudent" << (i+1) << ":\n";
        cout << "Enter ID: ";
        cin >> students[i].id;
        cin.ignore();  
        
        cout << "Enter Name: ";
        getline(cin, students[i].name);

        cout << "Enter Contact: ";
        getline(cin, students[i].contact);

        cout << "Enter Email: ";
        getline(cin, students[i].email);
    }

    cout << "\nStudent Data:\n";
    cout << "\n---------------------------------\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1;
        cout << "\nID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nContact: " << students[i].contact;
        cout << "\nEmail: " << students[i].email;
        cout << "\n---------------------------------\n";
    }

    return 0;
}
