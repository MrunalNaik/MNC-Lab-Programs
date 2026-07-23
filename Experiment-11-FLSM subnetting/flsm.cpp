#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string network;
    int prefix;
    int subnets;

    cout << "Enter Network Address (Example: 192.168.1.0): ";
    cin >> network;

    cout << "Enter Prefix Length: ";
    cin >> prefix;

    cout << "Enter Number of Subnets: ";
    cin >> subnets;

    int bitsBorrowed = ceil(log2(subnets));

    int newPrefix = prefix + bitsBorrowed;

    int blockSize = pow(2, 32 - newPrefix);

    cout << "\nNew Prefix = /" << newPrefix << endl;
    cout << "Block Size = " << blockSize << endl;

    // Extract first three octets
    int a,b,c,d;
    sscanf(network.c_str(), "%d.%d.%d.%d",&a,&b,&c,&d);

    cout << "\nSubnet Details\n";

    int start = 0;

    for(int i=1;i<=subnets;i++)
    {
        cout << "\nSubnet " << i << endl;

        cout << "Network Address : "
             << a<<"."<<b<<"."<<c<<"."<<start<<endl;

        cout << "Broadcast Address : "
             << a<<"."<<b<<"."<<c<<"."<<(start+blockSize-1)<<endl;

        cout << "Usable Host Range : "
             << a<<"."<<b<<"."<<c<<"."<<(start+1)
             <<" - "
             <<a<<"."<<b<<"."<<c<<"."<<(start+blockSize-2)
             <<endl;

        start += blockSize;
    }

    return 0;
}