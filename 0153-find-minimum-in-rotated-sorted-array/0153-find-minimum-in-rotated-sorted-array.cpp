class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low= 0;
        int high= n-1;
        int mini=INT_MAX;

        //logic->
        //find min in sorted part and then move to unsorted part

        while(low<=high){
            int mid= high-(high-low)/2;
            if(nums[low]<=nums[high]){
                //early break
                mini=min(mini,nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                //left part sorted;
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{//right part is sorted
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }
        return(mini!=INT_MAX)?mini:-1;
    }
};