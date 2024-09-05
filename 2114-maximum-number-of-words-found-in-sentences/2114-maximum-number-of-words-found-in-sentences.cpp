#include <sstream>
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxcount=INT_MIN;

        for(const auto& sentence:sentences){
            istringstream stream(sentence);
            string word;
            int count =0;
            while(stream>>word){
                count++;

            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};