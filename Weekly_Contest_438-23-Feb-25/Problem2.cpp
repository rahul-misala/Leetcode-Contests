// 3462. Maximum Sum With at Most K Elements
//leetcode : https://leetcode.com/problems/maximum-sum-with-at-most-k-elements/

class Solution {
    public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
            int n = grid.size();
            int m = grid[0].size();
            priority_queue< pair<int,int> > pq;
    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    pq.push({grid[i][j],i});
                }
            }
            long long sum = 0;
            while(k!=0){
                pair p = pq.top();
                int val = p.first;
                int idx = p.second;
                if(limits[idx] > 0){
                    sum += val;
                    limits[idx]--;
                    k--;
                }
                pq.pop();
            }
            return sum;
        }
    };