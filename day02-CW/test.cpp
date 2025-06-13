/*
    Random Generation Problem
    Author : Asif
    ID     : 2309005

*/

#include <bits/stdc++.h>
#include <fstream> // for file read and write
using namespace std;
typedef long long ll;

/*

For testing I/O:
-----------------------------------------------------------------
freopen("input.txt","r", stdin);
freopen("output.txt", "w", stdout);

*/

void solve()
{
    int start, end;

    cout << "Random Range" << endl;

    cout << "start: ";
    cin >> start;

    cout << "end: ";
    cin >> end;

    cout << endl;

    ofstream myFile("randomGeneratedNumbers.txt");

    for (int i = start; i < end; i++)
    {
        // cout << rand() % (end - start) + 1 << endl;
        myFile << rand() % (end - start) + 1;
        myFile << "\n";
    }
    myFile.close();

    string myText;

    // Read from the text file
    ifstream readFile("randomGeneratedNumbers.txt");

    int i = 1;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(readFile, myText))
    {
        // Output the text from the file
        int a = stoi(myText);
        cout << "Number " << "#" << i << ": " << a << endl;
        i++;
    }

    // Close the file
    readFile.close();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
    return 0;
}