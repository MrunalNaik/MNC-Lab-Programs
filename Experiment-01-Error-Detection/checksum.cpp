#include<iostream>
#include<string>
using namespace std;

//function to perform binary addition
string binaryAddition(string a,string b)
{
    string result(4,'0') ;//initialize result string with 4 zeros
    int carry=0;

    //start from right to left since binary addition is performed from least significant bit to most significant bit
    for(int i=3;i>=0;i--)
    {
        int sum=(a[i]-'0')+(b[i]-'0') +carry; //convert char to int and add carry')
        result[i]=(sum%2) + '0'; //store the result bit in the result string
        carry=sum/2; //calculate the carry for the next bit
    }

    while(carry) //if there is still a carry left after the addition
    {
        for(int i=3;i>=0;i--)
        {
            int sum=(result[i]-'0') + carry; //add the carry to the result
            result[i]=(sum%2) + '0'; //store the result bit in the result string
            carry=sum/2; //calculate the carry for the next bit
        }
    }
    return result;
}

//funtion to find one's complement
string onesComplement(string a)
{
    for(int i=0;i<a.length();i++)
    {
        if(a[i]== '0')
            a[i]='1';
        else
            a[i]='0';
    }
    return a;
}

void sender()
{
    string firstWord, secondWord, sum, checksum;
    cout<<"Enter the first 4-bit word: ";
    cin>>firstWord;

    cout<<"Enter the second 4-bit word: ";
    cin>>secondWord;

    sum=binaryAddition(firstWord,secondWord);

    checksum=onesComplement(sum);

    cout<<"sum: "<<sum<<"\n";
    cout<<"checksum: "<<checksum<<"\n";

    cout << "\n\nData Sent:\n";
    cout << firstWord << endl;
    cout << secondWord << endl;
    cout << checksum << endl;
}


void receiver()
{
    string firstWord, secondWord, checksum, sum, result;
    cout<<"Enter the first 4-bit word: ";
    cin>>firstWord;

    cout<<"Enter the second 4-bit word: ";
    cin>>secondWord;

    cout<<"Enter the checksum: ";
    cin>>checksum;

    sum=binaryAddition(firstWord,secondWord);
    result=binaryAddition(sum,checksum);

    cout<<"sum: "<<sum<<"\n";
    cout<<"result: "<<result<<"\n";

    if(result=="1111")
        cout<<"No error detected\n";
    else
        cout<<"Error detected\n";
}

int main()
{
    int choice;

    do{
        cout<<"\n****CHECKSUM ERROR DETECTION****\n";
        cout<<"1. Sender Side\n";
        cout<<"2. Receiver Side\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:sender();
                break;

            case 2:receiver();
                break;

            case 3:cout<<"Exiting the program.\n";
                break;

            default:cout<<"Invalid choice. Please try again.\n";
        }
    }while(choice!=3);
    // cout << binaryAddition("1110", "1111");
}

//the same program works for 8-bit, 16-bit, or any word length without changing the code.
// int n = firstWord.length();  
// string result(n, '0');

// for(int i = n - 1; i >= 0; i--)