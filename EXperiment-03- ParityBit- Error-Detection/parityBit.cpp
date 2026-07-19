#include<iostream>
#include<string>
using namespace std;

int countOnes(string data)
{
    int count =0;
    for(char c : data)
    {
        if(c == '1')
         count++;
    }
    return count;
}

char generateParityBit(string data, int choice)
{
    // choice == 1   // Even
    // choice == 2   // Odd
    int onesCount = countOnes(data);
    if(onesCount % 2 == 0 && choice == 1) //even parity
          return '0';
    else if(onesCount % 2 == 1 && choice == 1) //even parity
          return '1';
    else if(onesCount % 2 == 0 && choice == 2) //odd parity
          return '1';
    else
          return '0';
}

string sender(string data,int choice)
{
    char parityBit = generateParityBit(data, choice);
    return data + parityBit;
}

bool receiver(string receivedData, int choice)
{
    int onesCount = countOnes(receivedData);

    if(choice == 1)      // Even parity
        return (onesCount % 2 == 0);
    else                 // Odd parity
        return (onesCount % 2 == 1);
}

int main()
{
    int choice;
    int parityChoice;
    string data;
    string transmittedData;

    do
    {
        cout << "\n***** PARITY BIT *****\n";
        cout << "1. Sender\n";
        cout << "2. Receiver\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter the data bits: ";
                cin >> data;

                cout << "\nChoose Parity:\n";
                cout << "1. Even Parity\n";
                cout << "2. Odd Parity\n";
                cout << "Enter your choice: ";
                cin >> parityChoice;

                transmittedData = sender(data, parityChoice);

                cout << "Transmitted Frame: "
                     << transmittedData << endl;
                break;

            case 2:
                cout << "Enter the received frame: ";
                cin >> data;

                cout << "\nChoose Parity:\n";
                cout << "1. Even Parity\n";
                cout << "2. Odd Parity\n";
                cout << "Enter your choice: ";
                cin >> parityChoice;

                if(receiver(data, parityChoice))
                    cout << "No Error Detected\n";
                else
                    cout << "Error Detected\n";

                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    }while(choice != 3);

    return 0;
}