#include "processStrings.hpp"
#include <iostream>
using namespace std;

ProcessStrings::ProcessStrings(string filename)
{
    ifstream readFile(filename);
    string s1 = "";
    string s2 = "";
    getline(readFile, s1);
    getline(readFile, s2);
    m = s1.length();
    n = s2.length();
    arr = new int *[m + 1];
}

void ProcessStrings::buildMatrix()
{


    // 2D array has been declared and initialized
    for (int i = 0; i < (m + 1); i++)
    {
        arr[i] = new int[n + 1];
    }

    for (int i = 0; i < (m + 1); i++)
    {
        for (int j = 0; j < (n + 1); j++)
        {
            arr[i][j] = 0;
        }
    }
    print();

}

void ProcessStrings::lcs()
{
    buildMatrix();
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (m == 0 || n == 0)
            {
                cout << "this string has 0 elements" << endl;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }
}


std::string ProcessStrings::constructLcsArr()
{
    lcs();
    cout << "this is the value of m " << m << endl;
    cout << "this is the value of n " << n << endl;
    int index = arr[m][n];
    cout << "This is the value of index " << index << endl;
    string lcs(index + 1, '\0');

    int x = m;
    int y = n;

    // This code builds the string lcs with the correct string
    while (x > 1 && y > 1)
    {
        if (s1[x - 1] == s2[y - 1])
        {
            lcs[index - 1] = s1[x - 1];
            x--;
            y--;
            index--;
        }
        else if (arr[x - 1][y] > arr[x][y - 1])
        {
            x--;
        }
        else
        {
            y--;
        }
    }
    return lcs;
}

void ProcessStrings::print()
{

    for (int i = 0; i < (m + 1); i++)
    {
        for (int j = 0; j < (n + 1); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void ProcessStrings::deleteArr()
{
    int m = s1.length();
    for (int i = 0; i < (m + 1); i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}