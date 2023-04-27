#ifndef PROCESSSTRINGS
#define PROCESSSTRINGS
#include <string>
#include <fstream>

class ProcessStrings
{
private:
    std::string s1;
    std::string s2;

public:
    int m;
    int n;
    int **arr;
    ProcessStrings(std::string filename);
    void buildMatrix();
    void lcs();
    void print();
    void deleteArr();
    std::string constructLcsArr();
};

#endif