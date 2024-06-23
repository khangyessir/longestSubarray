#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int n = nums.size();
        int left = 0, maxLength = 0;
        for(int i = 0; i < n; ++i) {
            while(!maxDeque.empty() && nums[maxDeque.back()] <= nums[i]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(i);
            while(!minDeque.empty() && nums[minDeque.back()] >= nums[i]) {
                minDeque.pop_back();
            }
            minDeque.push_back(i);
            while(nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                ++left;
                if(maxDeque.front() < left) {
                    maxDeque.pop_front();
                }
                if(minDeque.front() < left) {
                    minDeque.pop_front();
                }
            }
            maxLength = max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};

//Example Testcase
int main(){
    Solution sol;
    vector<int> nums = {10,1,2,4,7,2};
    int limit = 5;
    cout << sol.longestSubarray(nums, limit) << endl;
    return 0;
}

