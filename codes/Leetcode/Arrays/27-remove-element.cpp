// Let me explain
/*
    # first, we just need to erase the elements matched with "value"
    # secondly, we have to keep in mind that the vector is variable in size (nums.size() is not same all the time) after each erasing.
    # so, we have to start from 0th index again
    # as everytime the i-iterator gets increased by 1 after each loop iteration, so wheneve erase is being performed, made it -1
    # -1 bcoz it will eventually get increased by 1 and will be 0 then the loop will start again.
    # here is how I explained my solution
    # Happy Coding

    -- Asif aka. therockhead 
*/

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            vector<int>nums_new;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == val)
                {
                    nums.erase(nums.begin()+i);
                    i = -1;
                }
            }
    
            return nums.size();
        }
    };