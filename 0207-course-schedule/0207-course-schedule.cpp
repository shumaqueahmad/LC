class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> adj(numCourses);  

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        // write pre req-> indegree
        // [1,0] 0->1 so indeg are the first elem
        vector<int> inde(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto it: adj[i]){
                inde[it]++;
            }
        }

        for(int i=0; i<inde.size(); i++){
            if(inde[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;

            for(auto it: adj[node]){
                inde[it]--;
                if(inde[it]==0) q.push(it);
            }
            
        }
        
        return cnt==numCourses;
    }
};