//3471. Find the Largest Almost Missing Integer
//Leetcode : https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/

class Solution {
    public:
        int largestInteger(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int,int> mp;
            int maxi =INT_MIN;
            int maxi1 =INT_MIN;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
                maxi1 = max(maxi1,nums[i]);
            }
            for(auto i : mp){
                if(i.second==1){
                    maxi = max(i.first,maxi);
                }
            }
            if(k==1){
                return (maxi==INT_MIN)?-1:maxi;
            }else if(k==n){
                return maxi1;
            }
            if(mp[nums[0]]==1 && mp[nums[n-1]]==1){
                return max(nums[0],nums[n-1]);
            }else if(mp[nums[0]]==1){
                return nums[0];
            }else if(mp[nums[n-1]]==1){
                return nums[n-1];
            }else{
                return -1;
            }
        }
    };