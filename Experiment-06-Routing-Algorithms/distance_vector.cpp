#include <iostream>
using namespace std;

int cost[10][10];          // original cost matrix entered by user
int distanceTable[10][10]; // Routing table that gets updated after each iteration.
int routers;               // Number of routers

void input()
{
    cout << "enter number of routers : ";
    cin >> routers;

    cout << "enter cost matrix(999 for infinity) : \n";
    for (int i = 0; i < routers; i++)
    {
        for (int j = 0; j < routers; j++)
        {
            cin >> cost[i][j];
            distanceTable[i][j] = cost[i][j];
        }
    }
}

// print the routing table after every iteration.
void display(int iteration)
{
    cout << "\nIteration " << iteration << endl;

    for (int i = 0; i < routers; i++)
    {
        cout << "\nRouter " << i + 1 << endl;
        cout << "Destination\tCost\n";

        for (int j = 0; j < routers; j++)
        {
            cout << j + 1 << "\t\t" << distanceTable[i][j] << endl;
        }
    }
}

void distanceVector()
{
    // But how do we know when to stop?
    // Distance Vector runs until no changes occur.
    // We'll use a flag.
    bool updated;
    int iteration = 1;
    do
    {
        updated = false;
        for (int i = 0; i < routers; i++)
        {
            for (int j = 0; j < routers; j++)
            {
                for (int k = 0; k < routers; k++)
                {
                    if (distanceTable[i][k] != 999 &&
                        distanceTable[k][j] != 999 &&
                        distanceTable[i][k] + distanceTable[k][j] < distanceTable[i][j])
                    // if (distanceTable[i][k] + distanceTable[k][j] < distanceTable[i][j])
                    {
                        distanceTable[i][j] = distanceTable[i][k] + distanceTable[k][j];
                        updated = true;
                    }
                }
            }
        }

        display(iteration); // display should be after all 3 for loops
        iteration++;
    } while (updated);

    if (!updated)
    {
        cout << "\nRouting tables converged.\n";
    }
}

int main()
{
    input();
    distanceVector();
    return 0;
}