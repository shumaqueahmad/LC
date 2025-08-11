#include <unordered_map>
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        std::unordered_map<int, int> frequencyMap;

        for (const auto& count : nums) {
            frequencyMap[count]++;
        }
        int maxfreq = 0;
        int maxelem = -1;
        for (const auto& pair : frequencyMap) {
            if (pair.second > maxfreq) {
                maxfreq = pair.second;
                maxelem = pair.first;
            }
        }
        return maxelem;
    }
};