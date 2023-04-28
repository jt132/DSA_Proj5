#ifndef LONGESTCOMMON
#define LONGESTCOMMON

#include <string>

class LongestCommon
{
public:
    std::string s1;
    std::string s2;
    LongestCommon(std::string filename);
    std::string LCS();
};

#endif