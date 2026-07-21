#include <iostream>

using namespace std;

int frames;
int windowSize;

void input()
{
    cout << "enter number of frames : ";
    cin >> frames;

    cout << "enter window size : ";
    cin >> windowSize;
}

void goBackN()
{
    int base = 1; // represents the first frame of the current window

    while (base <= frames)
    {
        // Implementation for Go-Back-N ARQ
        // send the frames in the current window
        for (int i = base; i < base + windowSize && i <= frames; i++)
        {
            // Implementation for sending each frame
            cout << "Sending frame " << i << endl;
        }

        // ask which frame is lost
        int lostFrame;
        cout << "Enter the frame number that is lost (0 if none): ";
        cin >> lostFrame;

        if (lostFrame == 0)
        {
            cout << "All frames sent successfully." << endl;
            base += windowSize; // move the window forward
        }
        else
        {
            cout << "Frame " << lostFrame << " lost. Resending from frame " << lostFrame << endl;
            cout << "Retransmitting...\n";

            for (int i = lostFrame;
                 i < base + windowSize && i <= frames;
                 i++)
            {
                cout << "Sending Frame " << i << " again\n";
            }
            base += windowSize; // move window forward
        }
    }
}

int main()
{
    input();
    goBackN();
}