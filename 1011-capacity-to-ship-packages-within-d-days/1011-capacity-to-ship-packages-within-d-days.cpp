class Solution {
public:
    int calc_days(vector<int>& weights, int mid){
        int day=1;
        int load=0;
        for(int i=0; i<weights.size(); i++){
            if(load+weights[i]>mid){
                day++;
                load=weights[i];
            }
            else
            load+=weights[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        auto maxindex= max_element(weights.begin(), weights.end());
        int min= *maxindex;
        int max= accumulate(weights.begin(),weights.end(),0);//summation of all elemets

        int low=min;
        int high=max;
        while(low<=high){
            int mid=(low+high)/2;//mid is the minimum capacity we are checking for
            int day=calc_days(weights,mid);
            int ans=INT_MAX;

            if(day<=days){
                high=mid-1;
                
            }
            else
            low=mid+1;
        }
        return low;
    }
};