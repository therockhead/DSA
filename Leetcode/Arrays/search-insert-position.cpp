class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int index = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == target){ // if target is found, then return the index only
                    return i;
                }
                else if(nums[i] < target){ // if not, then I am checking if the target is bigger than every index,
                    
                        index = i+1; // if so, saving the next position, jekhane store hobe
                }
            }
            return index;
        }
    };