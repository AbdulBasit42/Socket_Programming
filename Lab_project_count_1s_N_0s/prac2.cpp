// take input only 0's and 1's
// and count number of 0's and 1's
// and print the count of 0's and 1's

#include <iostream>
using namespace std;

int main()
{
    int n, i, count0 = 0, count1 = 0;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0 && arr[i] != 1)
        {
            cout << "Invalid Input" << endl;
            return 0;
        }
        
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else
        {
            count1++;
        }
    }
    cout << "Number of 0's are: " << count0 << endl;
    cout << "Number of 1's are: " << count1 << endl;
    return 0;

}