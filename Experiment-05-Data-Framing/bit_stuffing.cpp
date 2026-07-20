//uses Flag=01111110

#include <iostream>
#include <string>  
using namespace std;

const string FLAG = "01111110";

void sender()
{
    string data;

    cout << "Enter data: ";
    getline(cin >> ws, data); //cin >> data;

   string frame = FLAG + data + FLAG;
   
    cout << "Framed Data: " << frame << endl;
}

void receiver()
{
    string frame;

    cout << "Enter framed data: ";
    cin >> frame;
    string stuffed = frame.substr(8, frame.length() - 16); //string.substr(start_index, length)
    cout << "Stuffed Data: " << stuffed << endl;
}

int main()
{
    int choice;
    do
    {
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