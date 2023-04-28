#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "longestCommon.hpp"
#include "measureOfSimilarity.hpp"

using namespace std;

int main()
{

    cout << "Welcome to my program that finds the LCS!" << endl << endl;
    cout << "Part 1: " << endl;
    cout << "Using dynamic programming to find the LCS " << endl;
    LongestCommon lc("twoStrings.txt");
    string lcs = lc.LCS();
    int length = lcs.length()-1;
    cout << "Length of LCS: " << length << endl;
    cout << "Longest common subsequence: " << lcs << endl;
    cout << endl << "--------------------------------------------------------------------------------------" << endl << endl;

    cout << "Part 2: " << endl;
    cout << "Utilize 2xM matrices: " << endl;
    MeasureOfSimilarity mos("multiStrings.txt");
    mos.compareSimilarity();
    Sleep(800000);
}
