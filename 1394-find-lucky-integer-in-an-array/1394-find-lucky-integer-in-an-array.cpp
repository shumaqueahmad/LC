class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>m1;

        for(int i=0; i<arr.size(); i++){
            m1[arr[i]]++;
        }
        int maxi=INT_MIN;
        for(auto  x:m1){
            if(x.first==x.second){
                maxi= max(maxi,x.first);
            }
        }

        return (maxi==INT_MIN)?-1:maxi;
    }
};