#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
    freopen("generated.txt", "r", stdin);

    vector<int>v;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int var;
        cin >> var;
        v.push_back(var);
    }

    sort(v.begin(), v.end());

    ofstream fileM("generatedSorted.txt");

    fileM << n;
    fileM << "\n";
    
    for(int i = 0; i < n; i++)
    {
        fileM << v[i];
        fileM << "\n";

    }
    fileM.close();

    return 0;

}