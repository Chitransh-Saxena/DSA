#include <iostream>
#include <vector>

using namespace std;

string spiralSort(int arr[], int n)
{
    int left = 0;
    int right = n-1;

    while(left < right)
    {
        if(arr[left] > arr[right])
            return "no";

        left+=1;
        

        if (arr[right] > arr[left]) {
            return "no";
        }

        right-=1;
    }

    return "yes";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[10000];

    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << spiralSort(arr, n);
}