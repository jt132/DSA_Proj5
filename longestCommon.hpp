#ifndef LONGESTCOMMON
#define LONGESTCOMMON

#include <string>

class LongestCommon{
    public:
        std::string s1;
        std::string s2;
        std::string getS1(){return s1;}
        std::string getS2(){return s2;}
        void setS1(std::string s1){this->s1 = s1;}
        void setS2(std::string s2){this->s2 = s2;}
        LongestCommon(std::string filename);
        std::string LCS();
};

#endif