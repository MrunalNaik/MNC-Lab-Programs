#include<iostream>
#include<string>
using namespace std;

//perfrom modulo-2 divisio & returns remainder (1st write this function)
string modulo2Division(string dividend,string divisor)
{
    string temp=dividend;

    for(int i=0; i<=dividend.length() - divisor.length(); i++){
        if(temp[i] == '1')
        {
            //xor division with characters
            for(int j=0;j<divisor.length();j++)
            {
                if(temp[i+j]== divisor[j])
                    temp[i+j]='0';
                else
                    temp[i+j]='1';
            }
        }
    }
    return temp.substr(temp.length() - divisor.length() + 1);
}


// generate CRC bits
string generateCRC(string data, string generator)
{
    //append zeros to the data
    string augumentedData = data ;
    augumentedData.append(generator.length() - 1, '0');

    string remainder = modulo2Division(augumentedData, generator);

    return data + remainder;
}

//checks received frame
bool checkCRC(string receivedFrame, string generator)
{
    string remainder = modulo2Division(receivedFrame, generator);
     
    //if remainder is all zeros, then no error detected
    for(char bit : remainder)
    {
        if(bit != '0')
            return false;
    }
    return true;
}

void sender()
{
    string data, generator, transmittedFrame;

    cout<<"Enter the data bits: ";
    cin>>data;

    cout<<"Enter the generator polynomial: ";
    cin>>generator;

    transmittedFrame = generateCRC(data, generator);
    cout<<"Transmitted Frame: "<<transmittedFrame<<endl;
}

void receiver()
{
    string receivedFrame, generator;

    cout<<"Enter the received frame: ";
    cin>>receivedFrame;

    cout<<"Enter the generator polynomial: ";
    cin>>generator;

    if(checkCRC(receivedFrame, generator))
        cout<<"No error detected in the received frame.\n";
    else
        cout<<"Error detected in the received frame.\n";
}

int main()
{
    int choice;

    do{
        cout<<"\n****CRC ERROR DETECTION****\n";
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
}