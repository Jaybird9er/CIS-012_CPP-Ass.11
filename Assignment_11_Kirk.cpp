#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

// function prototypes
bool validateUserInputTime(int callHours, char colon, int callMins);
bool validateUserInputDay(char ch1, char ch2);
bool validateUserInputCallLength(int callTime);
double calculateTotalCost(int callHours, int callMins, char ch1, char ch2, int callTime);
char restartInput(char ans);

int main ()
{
    // restart beginning
    bool restart = true;
    while (restart == true)
    {
        system ("cls");

        // variables
        // time variables
        char ans;
        bool timeValidator = false;
        int callHours = 0;
        int callMins = 0;
        char colon;

        // day variables
        char ch1, ch2;
        bool dayValidator = false;

        // call variables
        int callTime = 0;
        bool callValidator = false;

        // calculation variables
        char test;

        // input
        // time validator
        cout << "Enter the time the call starts in 24-hour notation:" << endl;
        cin >> callHours;
        cin.get(colon);
        cin >> callMins;
        cin.ignore(1000, '\n');

        while (timeValidator == false)
        {
            timeValidator = validateUserInputTime(callHours, colon, callMins);
            if (timeValidator == false)
            {
                cout << "Invalid time input." << endl;
                cout << "Please try again." << endl;
                cout << endl;
                cout << "Enter the time the call starts in 24-hour notation:" << endl;
                cin >> callHours;
                cin.get(colon);
                cin >> callMins;
                cin.ignore(1000, '\n');
            }
        }
        cout << endl;

        // day validator
        cout << "Enter the first two letters of the day of the week:" << endl;
        cin >> ch1 >> ch2;
        cin.ignore(1000, '\n');
        while (dayValidator == false)
        {
            dayValidator = validateUserInputDay(static_cast<char>(toupper(ch1)), static_cast<char>(toupper(ch2)));
            if (dayValidator == false)
            {
                cout << "Invalid time input." << endl;
                cout << "Please try again." << endl;
                cout << endl;
                cout << "Enter the first two letters of the day of the week:" << endl;
                cin >> ch1 >> ch2;
                cin.ignore(1000, '\n');
            }
        }
        cout << endl;

        // call length validator
        cout << "Enter the length of the call in minutes:" << endl;
        cin >> callTime;
        while (callValidator == false)
        {
            callValidator = validateUserInputCallLength(callTime);
            if (callValidator == false)
            {
                cout << "Invalid time input." << endl;
                cout << "Please try again." << endl;
                cout << endl;
                cout << "Enter the length of the call in minutes:" << endl;
                cin >> callTime;
            }
        }

        // output
        // formating
        cout << fixed << showpoint << setprecision(2);

        // calculate expense
        cout << "Cost of the call: $";
        cout << calculateTotalCost(callHours, callMins, static_cast<char>(toupper(ch1)), static_cast<char>(toupper(ch2)), callTime) << endl;
        cout << endl;

        // restart program
        restart = restartInput(ans);
    }
    return 0;
}

// input functions
// user input time validator function
bool validateUserInputTime(int callHours, char colon, int callMins)
{
    // variables
    bool valid = false;

    // body
    while (valid == false)
    {
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            return false;
        }
        while (callHours < 0 || callMins < 0 || colon != ':')
        {
            return false;
        }
        while (callMins > 60)
        {
            return false;
        }
        while (callHours >= 24 && callMins > 00)
        {
            return false;
        }
        valid =  true;
    }
    return valid;
}

// user input day validator function
bool validateUserInputDay(char ch1, char ch2)
{
    // variables
    bool valid = false;

    //body
    while (valid == false)
    {
        if (ch1 == 'M' && ch2 == 'O')
        {
            valid = true;
        }
        else if (ch1 == 'T' && ch2 == 'U')
        {
            valid = true;
        }
        else if (ch1 == 'W' && ch2 == 'E')
        {
            valid = true;
        }
        else if (ch1 == 'T' && ch2 == 'H')
        {
            valid = true;
        }
        else if (ch1 == 'F' && ch2 == 'R')
        {
            valid = true;
        }
        else if (ch1 == 'S' && ch2 == 'A')
        {
            valid = true;
        }
        else if (ch1 == 'S' && ch2 == 'U')
        {
            valid = true;
        }
        else
        {
            return false;
        }
    }
    return valid;
}

bool validateUserInputCallLength(int callTime)
{
    // variables
    bool valid = false;

    // body
    while (valid == false)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            return false;
        }
        else if (callTime <= 0)
        {
            return false;
        }
        else
        {
            valid = true;
        }
    }
    return valid;
}

// output functions
// total cost function
double calculateTotalCost(int callHours, int callMins, char ch1, char ch2, int callTime)
{
    // variables
    double totalCost = 0;
    int day = 0;
    int startTime = 0;

    // hours conversion
    startTime = callHours * 60 + callMins;

    // body
    if (ch1 == 'S' && (ch2 == 'A' || ch2 == 'U'))
    {
        day = 0;
    }
    else
    {
        day = 1;
    }
    if (day == 1 && (startTime >= 480 && startTime <= 1080))
    {
        totalCost = callTime * 0.40;
    }
    else if (day == 1 && (startTime <= 480 || startTime >= 1080))
    {
        totalCost = callTime * 0.25;
    }
    else
    {
        totalCost = callTime * 0.15;
    }
    return totalCost;
}

// restart function
char restartInput(char ans)
{
    // variables
    bool restart;

    // body
    cout << "Do you want to repeat this program?" << endl;
    cout << "Y/N" << endl;
    cout << "> ";
    cin >> ans;
    ans = static_cast<char>(toupper(ans));
    while (ans != 'Y' && ans != 'N')
    {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Do you want to repeat this program?" << endl;
        cout << "Y/N" << endl;
        cout << "> ";
        cin >> ans;
        ans = static_cast<char>(toupper(ans));
    }
    if (ans == 'Y')
    {
        restart = true;
    }
    else
    {
        restart = false;
    }
    return restart;
}
