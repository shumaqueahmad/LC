class RandomizedSet {
private:
    vector<int> temp;
    
    unordered_map<int,int>mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            temp.push_back(val);
            mp[val]=temp.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            int ind= mp[val];
            int last= temp.back();
            
            temp[ind]= last;
            mp[last]= ind;

            temp.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randomIndex = rand() % temp.size();
        return temp[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */