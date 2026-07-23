#include <iostream>
#include <vector>
using namespace std;

// RZ Unipolar
void rzUnipolar(string bits)
{
    cout << "\nRZ Unipolar:\n";
    for(char b : bits)
    {
        if(b=='1')
            cout << "[1,0] ";
        else
            cout << "[0,0] ";
    }
    cout << endl;
}

// NRZ-L
void nrzL(string bits)
{
    cout << "\nNRZ-L:\n";
    for(char b : bits)
    {
        if(b=='1')
            cout << "1 ";
        else
            cout << "-1 ";
    }
    cout << endl;
}

// NRZ-I
void nrzI(string bits)
{
    cout << "\nNRZ-I:\n";

    int level = -1;

    for(char b : bits)
    {
        if(b=='1')
            level = -level;

        cout << level << " ";
    }

    cout << endl;
}

// Manchester
void manchester(string bits)
{
    cout << "\nManchester:\n";

    for(char b : bits)
    {
        if(b=='1')
            cout << "[1,-1] ";
        else
            cout << "[-1,1] ";
    }

    cout << endl;
}

// Differential Manchester
void diffManchester(string bits)
{
    cout << "\nDifferential Manchester:\n";

    int level = 1;

    for(char b : bits)
    {
        if(b=='0')
            level = -level;

        cout << "[" << level << "," << -level << "] ";

        level = -level;
    }

    cout << endl;
}

// AMI
void ami(string bits)
{
    cout << "\nAMI:\n";

    int polarity = 1;

    for(char b : bits)
    {
        if(b=='1')
        {
            cout << polarity << " ";
            polarity = -polarity;
        }
        else
        {
            cout << "0 ";
        }
    }

    cout << endl;
}

int main()
{
    string bits;

    cout << "Enter Binary Data: ";
    cin >> bits;

    rzUnipolar(bits);

    nrzL(bits);

    nrzI(bits);

    manchester(bits);

    diffManchester(bits);

    ami(bits);

    return 0;
}