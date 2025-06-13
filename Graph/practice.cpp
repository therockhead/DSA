// Fully My implementations from practice in practical class or LAB
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // n represents number of nodes 
    // m represents number of edges
    int n, m; 
    cin >> n >> m;

    // vector<char>adj[n+1];

    // for (int i = 0; i < m; i++) {
    //     char u, v;
    //     cin >> u >> v;
    //     adj[u-'A'].push_back(v);
    //     adj[v-'A'].push_back(u);
    // }
    // for (int i = 0; i < m; i++) {
    //     for (auto it: adj[i]) {
    //         cout << it << ' ';  
    //     }
    //     cout << '\n';
    // }

    int adj[m][m];
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        adj[u-'A'][v- 'A'] += 1;
        adj[v-'A'][u-'A'] += 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
    // vector<int>degrees;
    // for (int i = 0; i < m; i++) {
    //     int count = 0;
    //     for (int j = 0; j < m; j++) {
    //         if (adj[i][j] > 0) {
    //             count++;
    //         }
    //     }
    //     degrees.push_back(count);
    // }
    // int maximum = 0;
    // char hDegreeNode;
    // for (int i = 0; i < n; i ++) {
    //     char ch = 'A' + i;
    //     cout << "Degree of " << ch << ": " << degrees[i] << '\n';
    //     if (degrees[i] > maximum) {
    //         maximum = degrees[i];
    //         hDegreeNode = ch; // storing highest degree wala node
    //     }
    // }
    // // So ekhon highest degree node print korte pari and maximum degree tao print korte pari..
    // cout << "highest degree node: " << hDegreeNode << '\n';
    // cout << "And Highest Degree: " << maximum << '\n';

    // // Query part
    // char first, second;
    // cout << "Give two verteces/nodes to check if there remains any edge in between: ";
    // cin >> first >> second;
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (first-'A' == i && second-'A' == j) {
    //             cout << "No. of Edges Between: " << adj[i][j] << '\n';
    //             if (adj[i][j] > 0) {
    //                 cout << "Yes. There is a connection between " << first << " & " << second << endl;
    //             }
    //             else {
    //                 cout << "No connection left" << endl;
    //             }
    //         }
    //     }
    // }
    // // adjacent nodes
    // cout << "Adjacent Node Of: ";
    // char ch;
    // cin >> ch;
    // cout << "Adjacent Nodes Of " << ch << " are: ";
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (ch == (i + 'A'))
    //         {

    //             if (adj[i][j] > 0)
    //             {
    //                 cout << char(j + 'A') << ' ';
    //             }
    //         }
    //     }
        
    // } cout << '\n';

    // // check if any loop exists or not
    // bool loop = false;
    // for (int i = 0; i < m; i++)
    // {
    //     if (adj[i][i] > 0)
    //     {
    //         loop = true;
    //         break;
    //     }
    // }
    // if (loop)
    // {
    //     cout << "Loop Exists" << endl;
    // }
    // else
    // {
    //     cout << "No Loop Exists" << endl;
    // }

// Multigraph or Not
    bool multigraph = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] > 1) {
                multigraph = true;
                break;
            }
        }
    }
    if (multigraph) cout << "It is a Multi Graph.\n";
    else cout << "Not a Multigraph.\n";

// One Node Overlap Connection
    cout << "Enter 2 Nodes: " << '\n';
    char node1, node2;
    cin >> node1 >> node2;
    vector<int>ov;
    if (adj[node1- 'A'][node2-'A'] > 0) {
        cout << node1 << " and " << node2 << " are directly connected through edge.\n";
    }
    else {
        for (int i = 1; i < m; i++) {
            if (adj[i][node1 - 'A'] == 1) {
                ov.push_back(i);
                for (int j = (node1 - 'A')+1; j < m; j++) {
                    if (adj[i][j] == 1 && (node2-'A') == j) {
                        cout << "Yes, Connection Available Via One Node.\n";
                    }
                }
            }
        }
        cout << node1 << " to " << node2 << " via "<<  ov.size() << " Node: ";
        for (auto it: ov) {
            cout << char('A' + it) << " ";
        }
    }   
}
