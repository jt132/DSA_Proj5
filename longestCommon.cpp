/***************************************************************
Student Name: Joshua Tyrrell
File Name: longestCommon.cpp
Assignment number: Project05
This LongestCommon class contains the main logic for the first part
of the program. It is responsible for using dynamic programming
to find the longest common subsequence.
***************************************************************/

#include <iostream>
#include <fstream>
#include "longestCommon.hpp"

using namespace std;

// constructor that takes the filename and handles the
// reading of the file
LongestCommon::LongestCommon(std::string filename)
{
    ifstream readFile(filename);
    getline(readFile, s1);
    getline(readFile, s2);
}

// This function uses dynamic 2D array to utilize
// the classic LCS algorithm.
string LongestCommon::LCS()
{
    int m = s1.length();
    int n = s2.length();
    // 2D array has been declared and initialized
    int **arr = new int *[m + 1];
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

    // populate the matrix
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

    // This code builds the string lcs with the correct string
    int index = arr[m][n];
    string lcs(index + 1, '\0');
    int x = m;
    int y = n;

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