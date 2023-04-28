/***************************************************************
Student Name: Joshua Tyrrell
File Name: main.cpp
Assignment number: Project05
This is the main driver for the Longest Common Subsequence Problem
This uses the LCS algorithm in two different applications: printing out
LCS and it's length, and secondly using a matrix to compare the
similarity between different strings
***************************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include "longestCommon.hpp"
#include "measureOfSimilarity.hpp"

using namespace std;

int main()
{

    cout << "Welcome to my program that finds the LCS!" << endl
         << endl;
    cout << "Part 1: " << endl;
    cout << "Using dynamic programming to find the LCS " << endl;
    LongestCommon lc("twoStrings.txt");
    string lcs = lc.LCS();
    int length = lcs.length() - 1;
    cout << "Length of LCS: " << length << endl;
    cout << "Longest common subsequence: " << lcs << endl;
    cout << endl
         << "--------------------------------------------------------------------------------------" << endl
         << endl;

    cout << "Part 2: " << endl;
    cout << "Utilize 2xM matrices: " << endl;
    MeasureOfSimilarity mos("multiStrings.txt");
    mos.compareSimilarity();
}
