#include<iostream>
#include<string>
using namespace std;

const string VIOLATION = "<V>";

void sender()
{
    string data;

    cout << "Enter data: ";
    getline(cin >> ws, data);// to take input with spaces

    string frame = VIOLATION + data + VIOLATION;
    cout << "Framed Data: " << frame << endl;
}

void receiver()
{
    string frame;

    cout << "Enter framed data: ";
    getline(cin >> ws, frame); //cin>>frame; // to take input with spaces

    //see the substr 
    string data = frame.substr(VIOLATION.length(),
                               frame.length() - 2 * VIOLATION.length());

    cout << "Original Data: " << data << endl;
}

int main()
{
    int choice;
    do
    {
        cout<<"physical layer violation program\n";
        cout << "\n1.sender\n2.receiver\n3.exit\nenter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sender();
            break;
        case 2:
            receiver();
            break;
        case 3:
            cout << "exit";
            break;
        default:
            cout << "invalid choice";
        }
    } while (choice != 3);
}