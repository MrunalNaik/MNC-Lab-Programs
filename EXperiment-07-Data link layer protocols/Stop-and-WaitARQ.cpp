#include <iostream>
using namespace std;

int frames;
void input()
{

    cout << "enter number of frames : ";
    cin >> frames;
}

void stopAndWait()
{
    int ack;
    for (int i = 0; i < frames; i++)
    {
        do
        {
            cout << "Sending frame " << i + 1 << endl;
            cout << "was ACK received for frame " << i + 1 << "? (1 = yes, 0 = no) : ";
            cin >> ack;

            if (ack == 0)
                cout << "frame "
                     << i + 1 << " ACk lost, sending frame " << i + 1 << " again\n";
        } while (ack == 0);

        cout << endl;
        cout << "frame " << i + 1 << " sent successfully\n";
    }

    cout << "\nTransmission Completed Successfully.\n";
}

int main()
{
    input();
    stopAndWait();
    return 0;
}