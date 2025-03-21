#include<iostream>

using namespace std;


int linearSearch(int arr[], int n, int search);
int binarySearch(int arr[], int n, int search);
void sorting(int arr[], int n);

int main()
{
    freopen("generated.txt", "r", stdin);

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int search;
    cin >> search; // last element from the file goes in search mainly

    // change korte chaile file e change kora lagbe
    // jehetu file theke input shb

    int l = linearSearch(arr, n, search);
    int b = binarySearch(arr, n, search);
    cout << "steps in linear: " << l << endl;
    cout << "steps in binary search: " << b << endl;
    cout << "Steps Comparison: "<< (l-b) << " times more steps needed\n for linear search than binary search." << endl;


}
void sorting(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { 
                swap(arr[j], arr[j + 1]);  
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

int linearSearch(int arr[], int n, int search)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        count++;
        if(arr[i] == search)
        {
            break;
        }
    }

    return count;
}
int binarySearch(int arr[], int n, int search)
{
    sorting(arr, n);

    int start, mid, end;

    // shobar prothome arki
    start = 0;
    end = n - 1;
    int searchCount = 0;

    int count = 0;
    int flag = 0;


    while (start <= end)
    {
            mid = (start+end)/2;

            if (arr[mid] == search)
            {
                break;
            }
            if (arr[mid] < search)
            {
                start = mid + 1;
                // end ta same thaktese
            }
            else
            {
                end = mid -1;
                // start ta same thaktese but shamner dik theke shrink kore nitesi 
            }
            searchCount++;
    }

    return searchCount;
}