#include <iostream>

using namespace std;

int inputData(string*&, double**&);
void displayData(string*, double**, int);
void cleanHeap(string*, double**, int);

int main() {
    string* names = nullptr;
    double** scores = nullptr;
    int numStudents = inputData(names, scores);
    displayData(names, scores, numStudents);
    cleanHeap(names, scores, numStudents);
}

/*
RECEIVES: pointer to string of names (currently empty), pointer to a double
pointer (also currently empty) and both are called by reference
RETURNS: the number of students (accepted from the user)
FUNCTION: accepts all the required data from the user - number of students,
names, number of tests, and grades. - does not accept a negative value for
number of students or number of tests.
*/
int inputData(string*& names, double**& grades) {
    int numStudents;
    do {
        cout << "Enter the number of students: "; 
        cin >> numStudents;
    } while (numStudents <= 0);

    names = new string [numStudents];
    grades = new double* [numStudents];
    cin.ignore();
    int count = 1;

    do {
        int numTests;
        cout << "Enter the student's name: ";
        getline(cin, names[count - 1]);

        do {
            cout << "Enter how many tests " << names[count - 1] << " took: ";
            cin >> numTests;
        }while(numTests <= 0);

        * (grades + count - 1) = new double [numTests];
        grades[count - 1][0] = numTests; /*stores the number of tests in the
        [0] index position making it easy to print*/ 

        for(int i = 0; i < numTests; i++) {
            cout << "Enter grade #" << i + 1 << " ";
            cin >> grades[count - 1][i + 1];
        }
        cin.ignore();
        count++;
    } while(count <= numStudents);

    return numStudents;
}

/*
RECEIVES: a pointer to an array of names, a pointer to a double pointer to 
grades of students and the number of students
RETURNS: nothing - just used to display 
FUNCTION: prints all the data on the heap
*/
void displayData(string* names, double** grades, int numStudents) {
    cout << "You have " << numStudents << " students in the system." << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Name of student #" << i + 1 << ": " << *(names + i) << endl;
        cout << "Grades for student #" << i + 1 << ": ";
        for (int j = 0; j < grades[i][0]; j++) {
            cout << grades[i][j + 1] << " ";
        }
        cout << endl;
    }
}

/*
RECEIVES: a pointer to an array of names, a pointer to a double pointer to 
grades of students and the number of students
RETURNS: nothing 
FUNCTION: used to clean the heap after everything is done
*/
void cleanHeap(string* names, double** grades, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        delete[] grades[i];
    }
    delete[] grades;
    delete[] names;
}
