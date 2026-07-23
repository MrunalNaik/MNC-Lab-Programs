#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;

    cout<<"Enter Number of Departments: ";
    cin>>n;

    vector<int> hosts(n);

    for(int i=0;i<n;i++)
    {
        cout<<"Hosts Required for Department "<<i+1<<": ";
        cin>>hosts[i];
    }

    sort(hosts.begin(), hosts.end(), greater<int>());

    int a=192,b=168,c=1,current=0;

    cout<<"\nVLSM Allocation\n";

    for(int i=0;i<n;i++)
    {
        int needed = hosts[i] + 2;

        int bits=0;

        while(pow(2,bits)<needed)
            bits++;

        int block = pow(2,bits);

        int prefix = 32 - bits;

        cout<<"\nDepartment "<<i+1<<endl;

        cout<<"Hosts Required : "<<hosts[i]<<endl;

        cout<<"Subnet Mask : /"<<prefix<<endl;

        cout<<"Network Address : "
            <<a<<"."<<b<<"."<<c<<"."<<current<<endl;

        cout<<"Broadcast Address : "
            <<a<<"."<<b<<"."<<c<<"."<<(current+block-1)<<endl;

        cout<<"Host Range : "
            <<a<<"."<<b<<"."<<c<<"."<<(current+1)
            <<" - "
            <<a<<"."<<b<<"."<<c<<"."<<(current+block-2)
            <<endl;

        current += block;
    }

    return 0;
}