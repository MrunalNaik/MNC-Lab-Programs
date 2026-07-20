#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPowerOfTwo(int n);//since insertParity was giving error becuase ispoweroftwo was declared after it, so declared it here
int calculateParityBits(int dataBits)
{
    int parityBits = 0;
    while (pow(2, parityBits) < (dataBits + parityBits + 1)) // impotant note (not >=)
    {
        parityBits++;
    }
    return parityBits;
}

string insertParityBits(string data, int parityBits)
{

    string hammingCode = "";

    for (int i = 1, j = 0; i <= (data.length() + parityBits); i++)
    {
        if (isPowerOfTwo(i))
        {
            hammingCode += '0'; // insert parity bit
        }
        else
        {
            hammingCode += data[j]; // insert data bit
            j++;
        }
    }
    return hammingCode;
}

void calculateParityValues(string &hammingCode, int parityBits)
{

    for (int i = 0; i < parityBits; i++)
    {
        int parityPosition = pow(2, i);
        int onesCount = 0;
        for (int j = 1; j <= hammingCode.length(); j++)
        {
            if (j & parityPosition && j!=parityPosition) // check if the jth bit is covered by the ith parity bit
            {
                if (hammingCode[j - 1] == '1')
                {
                    onesCount++;
                }
            }
        }

        char parity;
        if (onesCount % 2 == 0)
            parity = '0';
        else
            parity = '1';

        hammingCode[parityPosition - 1] = parity;
    }
}

bool isPowerOfTwo(int n)
{
    int r = 0;

    while (pow(2, r) <= n)
    {
        if (pow(2, r) == n)
            return true;

        r++;
    }

    return false;
}

void sender()
{
    string data;
    cout << "Enter binary data: ";
    cin >> data;
    int parityBits = calculateParityBits(data.length());
    string hammingCode = insertParityBits(data, parityBits);
    calculateParityValues(hammingCode, parityBits);

    cout << "Hamming Code: " << hammingCode << endl;
}

void receiver()
{
    string receivedCode;
    cout << "Enter received Hamming code: ";
    cin >> receivedCode;

    int parityBits = 0;

    while (pow(2, parityBits) <= receivedCode.length())
    {
        parityBits++;
    }

    int errorPosition = 0;

    for (int i = 0; i < parityBits; i++)
    {
        int parityPosition = pow(2, i);
        int onesCount = 0;

        for (int j = 1; j <= receivedCode.length(); j++)
        {
            if (j & parityPosition)
            {
                if (receivedCode[j - 1] == '1')
                    onesCount++;
            }
        }

        if (onesCount % 2 != 0)
        {
            errorPosition += parityPosition;
        }
    }

    if (errorPosition == 0)
    {
        cout << "No error detected." << endl;
    }
    else
    {
        cout << "Error detected at position: " << errorPosition << endl;

        if (receivedCode[errorPosition - 1] == '0')
            receivedCode[errorPosition - 1] = '1';
        else
            receivedCode[errorPosition - 1] = '0';

        cout << "Corrected Hamming Code: " << receivedCode << endl;
    }
}

int main()
{
    int choice;
    do
    {
    cout << "Hamming Code Error Correction\n";
    cout << "1. Sender\n";
    cout << "2. Receiver\n";
    cout<<"3. Exit\n";
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
        break;
    }
    }while(choice != 3);

    return 0;
}