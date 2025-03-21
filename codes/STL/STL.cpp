#include <bits/stdc++.h>

using namespace std;

/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/

void vectorCheat();
void priority_queue_Cheat();


int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //vectorCheat();

    priority_queue_Cheat();

    return 0;
}

void vectorCheat()
{
    vector<pair<int, int>>vec;

    // use of push_back()
    vec.push_back({1, 2});
    vec.push_back({3, 4});

    cout << vec[0].first << ", ";
    cout << vec[0].second << endl;

    cout << vec[1].first << ", ";
    cout << vec[1].second << endl;

    cout << "Declaring variable vector v(number_of_index, value)";
    cout << endl << "values will be like this for v(5, 100)" << endl;
    vector<int> v(5, 100);

    for(int i = 0; i < 5; i++){
        cout << v[i] << endl;
    }

    // Copying one vector into other
    vector<int> v1(v);

    // printing the value of v1, which took copy of v 
    cout << "---------\n";
    for(int i = 0; i < 5; i++)
    {
        cout << v1[i] << endl;
    }


// using iterators
    vector<int>v2;

    v2.push_back(12);
    v2.push_back(20);

    // iterator declaration
    vector<int>::iterator it = v2.begin();
        // v.end(), v.rend(), v.rbegin()
    
    cout << *(it) << endl; // prints the 0th element
    it++;
    cout << *(it) << endl; // prints the 1st element

    v2.push_back(8);
    cout << "v.back() = " << v2.back();

    
    vector <int> copy;

    copy.insert(copy.begin(), v2.begin(), v2.end());

    cout << "printing after copying" << endl;
    for(auto it: copy)
    {
        cout << it << endl; 
    }
    cout << v.empty();
    


    return;
    
}
void priority_queue_Cheat()
{
    priority_queue <int> pq;

    pq.push(100);
    pq.push(10);
    pq.push(1);
    pq.push(500);
    pq.push(101);

    cout << "pq.top() is " << pq.top() << endl;
    // automatically keeps the highest value on top
}