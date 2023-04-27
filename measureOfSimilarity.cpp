#include "measureOfSimilarity.hpp"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

MeasureOfSimilarity::MeasureOfSimilarity(std::string filename)
{
    ifstream readFile(filename);
    string s1;
    string num = "";

    getline(readFile, num);
    int numStrings = stoi(num);
    cout << numStrings << endl;

    for (int i = 0; i < numStrings; i++)
    {
        getline(readFile, s1);
        vec.push_back(s1);
    }
}

void MeasureOfSimilarity::compareSimilarity()
{

    cout << "print vector: " <<endl;
    for(int i = 0; i< vec.size(); i++){
        cout << vec.at(i) << "   ";
    }
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec.size()-1; j++){
           // LCS(vec.at(i), vec.at(j+1));

        }
    }

}

void MeasureOfSimilarity::LCS(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int longer = 0;
    if(s1.length() > s2.length()){
        longer = s2.length();
    }
    else{
        longer = s1.length();
    }
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
                cout << "no elements!!!" << endl;
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
    int lcsLength = arr[m][n];
    cout << "this is the lcsLength" << lcsLength << endl;
    // cleans up the array

    for (int i = 0; i < (m + 1); i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}