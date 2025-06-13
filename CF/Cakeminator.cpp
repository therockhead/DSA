// @Author: Asif aka.TheRockHead
#include <bits/stdc++.h>

using namespace std;

/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/

int main()
{
    int row, col;
    cin >> row >> col;
    char arr[row][col];

    set<int>p, q;
    

    int flag;
    for (int i = 0; i < row; i++)
    {
        flag = 0;
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'S')
            {
                p.insert(i);
                q.insert(j);
            }
        }
        
    }
    
    
    int r = row - p.size();
    int c = col - q.size();

    
    cout << ((r*col + c* row) - r*c) << endl;


    return 0;

}