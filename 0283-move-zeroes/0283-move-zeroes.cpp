class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // instead of sorting, approach is to find the first zero element and
        // swap it with a non zero element
        int n = nums.size();
        /*int j = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        if (j == -1) {
            return;
        }

        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[j], nums[i]);
                j++;
            }
        }*/

        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1-i; j++){
                if(nums[j]==0){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        
    }
};