#ifndef MEASUREOFSIMILARITY
#define MEASUREOFSIMILARITY
#include <string>

class MeasureOfSimilarity{
    public:
        MeasureOfSimilarity(std::string filename);
        void compareSimilarity();
        std::string LCS(std::string s1, std::string s2);
};

#endif