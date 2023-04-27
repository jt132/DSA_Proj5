#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

string LCS(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    // 2D array has been declared and initialized
    int **arr = new int *[m + 1];
    for (int i = 0; i < (m + 1); i++)
    {
        arr[i] = new int[n + 1];
    }

    for (int i = 0; i < (m+1); i++){
         for (int j = 0; j < (n + 1); j++)
        {
            arr[i][j] = 0;
        }
    }
/*
cout << "Initial Matrix:" << endl;
for (int i = 0; i < (m+1); i++){
         for (int j = 0; j < (n + 1); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
  */  

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (m == 0 || n == 0)
            {
                return 0;
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
/*
cout << "Matrix after populated: " << endl;
for (int i = 0; i < (m+1); i++){
         for (int j = 0; j < (n + 1); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
*/
    int index = arr[m][n];
    string lcs(index + 1, '\0');

    int x = m;
    int y = n;

//This code builds the string lcs with the correct string
    while (x > 0 && y > 0)
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

    // cleans up the array

    for (int i = 0; i < (m + 1); i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return lcs;
}

int main()
{

    ifstream readFile("twoStrings.txt");
    string s1 = "";
    string s2 = "";
    getline(readFile, s1);
    getline(readFile, s2);

    string lcs = LCS(s1, s2);
    int length = lcs.length()-1;

    cout << "Length of LCS is " << length << endl;
    cout << "Longest common subsequence is " << lcs << endl;


    Sleep(800000);
}
