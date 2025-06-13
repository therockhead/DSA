#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k; // k days 
    cin >> n >> k;

    priority_queue<pair<int, int>> p;

    for(int i = 0; i < n; i++)
    {
        int var;
        cin >> var;

        p.push({var, i});        
    }
    

    pair<int,int>v[n];
    for(int i = 0; i < n; i++)
    {
        v[i].first = (p.top().first); // values
        v[i].second = (p.top().second); // keys
        // cout << p.top().first << " ";
        p.pop();
    }


    int sum = 0;
    int count = 0;
    int last = 0;
    for(int j = n-1; j >= 0; j--)
    {
        if(sum >= k) break;
        sum += v[j].first;
        count++;
        last = j;
    }

    cout << count << endl;
    for(int i = last; i < n; i++)
    {
        cout << v[i].second + 1 << " ";
    }
    
    
}
void solve02()
{
    int n, k; // k days 
    cin >> n >> k;

    pair<int, int> p[n];
    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int var;
        cin >> var;

        p[i].first = var;
        p[i].second = i;         
    }
    sort(p,p+n);
    
    for(int i = 0; i < n; i++)
    {
        if(k < p[i].first) break;
        v.push_back(p[i].second + 1);
        k = k - p[i].first;

    }
    sort(v.begin(), v.end());

    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve02();


    return 0;
}