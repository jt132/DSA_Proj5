#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "longestCommon.hpp"
#include "measureOfSimilarity.hpp"

using namespace std;

int main()
{

    MeasureOfSimilarity mos("multiStringsTest.txt");
    mos.compareSimilarity();
    //LongestCommon lc("twoStrings.txt");
    //string lcs = lc.LCS();
    //int length = lcs.length()-1;
    //cout << "Length of LCS is " << length << endl;
    //cout << "Longest common subsequence is " << lcs << endl;
    
    Sleep(800000);
}
