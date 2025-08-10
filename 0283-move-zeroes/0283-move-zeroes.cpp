class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // instead of sorting, approach is to find the first zero element and
        // swap it with a non zero element
        int n = nums.size();
        int j=-1; //tracks zero elem
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return;
        for(int i=j+1; i<n; i++){
            if(nums[i]!=0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};