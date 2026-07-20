#include<iostream>
#include<string>
using namespace std;
// bhyte stuffing uses FLAG
//FLAG = $
//ESC = /

const char FLAG = '$';
const char ESC = '/';

void sender()
{
    string data;

    cout << "Enter data: ";
    getline(cin >> ws, data);

    string frame = "";

    frame += FLAG; // Start of frame

    for (char ch : data)
    {
        if (ch == FLAG || ch == ESC)
        {
            frame += ESC; // Escape character
        }
        frame += ch;
    }

    frame += FLAG; // End of frame

    cout << "Framed Data: " << frame << endl;
}

void receiver()
{
    string frame;

    cout << "Enter framed data: ";
    cin >> frame;

    string data = "";

    for(int i=1; i<frame.length() -1 ; i++)
    {
        if(frame[i] == ESC)
        {
            i++;
            data += frame[i];
        }
        else
        {
            data += frame[i];
        }
  
    }

    cout << "Original Data: " << data << endl;
}

int main()
{
    int choice;
    do
    {
        cout << "Byte Stuffing\n";
        cout << "1. Sender\n";
        cout << "2. Receiver\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
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
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}

