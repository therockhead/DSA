#include <bits/stdc++.h>

using namespace std;

/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/

int main()
{

    int games; 
    cin >> games;

    set<int>p;
    // set<int>q;
    int levels_p, levels_q;

    cin >> levels_p;

    for (int i = 0; i < levels_p; i++)
    {
        int val;
        cin >> val;
        p.insert(val);

    }

    cin >> levels_q;

    for(int i = 0; i < levels_q; i++)
    {
        int val;
        cin >> val;
        p.insert(val);
    }
    
    int actual = (games*(games+1))/2;
    int sum = 0;
    for(auto i:p)
    {

        sum+= i;
    }


    if(levels_p == 0 && levels_q == 0)
    {
        cout << "Oh, my keyboard!" << endl;
    }
    else if(actual > sum)
    {
        cout << "Oh, my keyboard!" << endl;
    }
    else{
        cout << "I become the guy." << endl;
        // cout << actual << endl;
        // cout << sum << endl;
    }

    return 0;
}