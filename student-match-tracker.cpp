#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void input(string names[], int matches[], int size);
void display(string names[], const int matches[], int size);
void displayMostMatches(const string names[], const int matches[], int size);
double mean(const int matches[], int num);
void sortStudents(string names[], int matches[], int size);

//****************************************************************************************************

int main ()
{
    int size;
    int* matches = nullptr;
    string* names = nullptr;

    double meanMatches;

    cout << "How many students were involve in the survey? ";
    cin >> size;
    cout << endl;

    matches = new int[size];
    names = new string[size];

    input(names, matches, size);
    display(names, matches, size);

    cout << endl;

    displayMostMatches(names, matches, size);

    meanMatches = mean(matches, size);
    cout << endl 
         << fixed << setprecision(2) << "The mean of cricket matches: " << meanMatches << endl;

    sortStudents(names, matches, size);

    display(names, matches, size);

    cout << endl;

    delete[] matches;
    delete[] names;

    matches = nullptr;
    names = nullptr;

    return 0;
}

//****************************************************************************************************

void input(string names[], int matches[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the name of Student: " << i + 1 << ": ";
        cin.ignore();
        getline(cin, names[i]);

        do 
        {
            cout << "Enter the numbers of matches played by " << names[i] << ": ";
            cin >> matches[i];
            cout << endl;

            if (matches[i] < 0)
            {
                cout << "Please re-enter a non-negative number. " << endl;
            }
        }
        while (matches[i] < 0);
    }
}

void display(string names[], const int matches[], int size)
{
    cout << "Names & Matches: "
         << endl << endl;
    
    for (int i = 0; i < size; i++)
    {
        cout << setw(10) << "Name: " << names[i]
             << "\tMatches: " << matches[i] << endl;
    }
}

void displayMostMatches(const string names[], const int matches[], int size)
{
    int maxMatch = 0;
    int maxIndex = 0;

    for (int i = 0; i < size; i++)
    {
        if (matches[i] > maxMatch)
        {
            maxMatch = matches[i];
            maxIndex = i; 
        }
    }

    if (maxIndex >= 0)
    {
        cout << "Most cricket matches played: " << names[maxIndex] << " played " << maxMatch 
             << " matches." << endl; 
    }
}

double mean(const int matches[], int num)
{
    double total = 0.0;

    for (int i = 0; i < num; i++)
    {
        total += matches[i];    
    }

    return static_cast<double>(total) / num;
}

void sortStudents(string names[], int matches[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (names[j] > names[j + 1])
            {
                swap(names[j], names[j + 1]);
                swap(matches[j], matches[j + 1]);
            }
        }
    }
}

//****************************************************************************************************

/*

How many students were involve in the survey? 5

Enter the name of Student: 1: Max Tulip
Enter the numbers of matches played by Max Tulip: 16

Enter the name of Student: 2: Jack Hammer
Enter the numbers of matches played by Jack Hammer: 12

Enter the name of Student: 3: Noah Smith
Enter the numbers of matches played by Noah Smith: 8

Enter the name of Student: 4: Quinton Jones
Enter the numbers of matches played by Quinton Jones: 23

Enter the name of Student: 5: Abe Plep
Enter the numbers of matches played by Abe Plep: 4

Names & Matches:

    Name: Max Tulip     Matches: 16
    Name: Jack Hammer   Matches: 12
    Name: Noah Smith    Matches: 8
    Name: Quinton Jones Matches: 23
    Name: Abe Plep      Matches: 4

Most cricket matches played: Quinton Jones played 23 matches.

The mean of cricket matches: 12.60
Names & Matches:

    Name: Abe Plep      Matches: 4
    Name: Jack Hammer   Matches: 12
    Name: Max Tulip     Matches: 16
    Name: Noah Smith    Matches: 8
    Name: Quinton Jones Matches: 23

*/