#ifndef MEASUREOFSIMILARITY
#define MEASUREOFSIMILARITY
#include <vector>
#include <string>

class MeasureOfSimilarity{
    public:
        std::vector<std::string> vec;
        MeasureOfSimilarity(std::string filename);
        void compareSimilarity();
        double LCS(std::string s1, std::string s2);
        double calculateLength(std::string s1, std::string s2);
};

#endif