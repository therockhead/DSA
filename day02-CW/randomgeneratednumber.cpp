#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{

    ofstream myFile("generated.txt");

    int start, end;

    cin >> start;
    cin >> end;

    myFile << end;
    myFile << "\n";


    for (int i = 0; i < end; i++)
    {
        myFile << rand() % (start - end) + 1;
        myFile << "\n";
    }
    
    myFile.close();

    return 0;

}