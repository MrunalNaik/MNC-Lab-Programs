#include<iostream>
#include<string>
using namespace std;

//multiframe code
void sender()
{
    string data;

    cout << "Enter data: ";
    cin >> data;

    int frameSize;

    cout << "Enter frame size: ";
    cin >> frameSize;

    string frame = "";

    for(int i = 0; i < data.length(); i += (frameSize - 1))
    {
        int characters;

        if(i + frameSize - 1 <= data.length())
            characters = frameSize - 1;
        else
            characters = data.length() - i;

        frame += (characters + 1) + '0';

        for(int j = 0; j < characters; j++)
        {
            frame += data[i + j];
        }
    }

    cout << "Framed Data: " << frame << endl;
}

void receiver()
{
    string frame;

    cout << "Enter framed data: ";
    cin >> frame;

    string data = "";

    int i = 0;

    while(i < frame.length())
    {
        int count = frame[i] - '0';

        i++;

        for(int j = 1; j < count; j++)
        {
            data += frame[i];
            i++;
        }
    }

    cout << "Original Data: " << data << endl;
}

int main()
{
    int choice;
    do
    {   cout<<"character count program\n";
        cout<<"\n1.sender\n2.receiver\n3.exit\nenter your choice:";
        cin>>choice;

        switch(choice)
        {
            case 1: sender();
                    break;
            case 2: receiver();
                    break;
            case 3: cout<<"exit";
                    break;
            default: cout<<"invalid choice";
        }
    }while(choice!=3);
}

/*simple single frame code
void sender()
{
     string data;

     cout<<"enter data:";
     cin>>data;

     string frame;
     char c=(data.length()) + '0';
    // frame[0] = c;// frame is empty so frame[0] doesn't exit
     frame=frame+c;

    for(char ch: data)
     {
        frame=frame+ch;
     }
     
     cout<<"frame:"<<frame<<endl;
}


void receiver()
{
    string frame;
    cout<<"enter frame:";
    cin>>frame;

    int length=frame[0]-'0';// to check whether frame is valid 
    
    if(length!=frame.length()-1)
    {
        cout<<"invalid frame !";
        return;
    }


    cout<<"received data :";

    for(int i=1;i<frame.length();i++)
    {
        cout<<frame[i];
    }

}

*/