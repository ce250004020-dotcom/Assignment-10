#include <iostream>
#include <string>
#include <limits>  

using namespace std;

struct Marks {
    float math;
    float science;
    float english;
};

struct Student {
    int rollNo;
    string name;
    Marks marks;
};

float computeAverage(const Marks& m) {
    return (m.math + m.science + m.english) / 3.0f;
}

int main() {
    Student students[5];
    float highestAvg = numeric_limits<float>::lowest(); 
    float lowestAvg = numeric_limits<float>::max();  
    int highestIndex = -1, lowestIndex = -1;

    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        
        cout << "Name: ";
        cin.ignore();  // To ignore the newline left by previous cin
        getline(cin, students[i].name);
        
        cout << "Enter marks for math, science, and english:\n";
        cout << "Math: ";
        cin >> students[i].marks.math;
        cout << "Science: ";
        cin >> students[i].marks.science;
        cout << "English: ";
        cin >> students[i].marks.english;
        
        
        float avg = computeAverage(students[i].marks);

    
        if (avg > highestAvg) {
            highestAvg = avg;
            highestIndex = i;
        }

        
        if (avg < lowestAvg) {
            lowestAvg = avg;
            lowestIndex = i;
        }
    }

    
    cout << "\nStudent with the highest average marks:\n";
    cout << "Name: " << students[highestIndex].name << ", Roll No: " << students[highestIndex].rollNo
         << ", Average Marks: " << highestAvg << endl;
    
    cout << "\nStudent with the lowest average marks:\n";
    cout << "Name: " << students[lowestIndex].name << ", Roll No: " << students[lowestIndex].rollNo
         << ", Average Marks: " << lowestAvg << endl;

    return 0;
}
