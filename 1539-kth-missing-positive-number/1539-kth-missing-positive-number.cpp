class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> mapp;
        for(int i=0; i<arr.size(); i++){
            mapp.insert(arr[i]);
        }
        int j=1;
        while(1){
            if(mapp.find(j)!=mapp.end()){//elemet mila hai:
                j++;
                continue;
            }
            else{
                k--;
                if(k==0){
                    return j;
                    break;
                }
                j++;
            }
        }
        return 0;
    }
};