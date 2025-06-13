/* Author: Asif aka therockhead */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[0] == 9) { // if all are 9, implemented after first error
            int count = 1;
            int len = digits.size();
            for (int i = 1; i < len; i++) {
                if (digits[i] == 9) count++;
            }
            if (count == len) { 
                digits[0] = 1; // at beginning, i am adding 1
                for (int i = 1; i < len; i++) {
                    if (digits[i] == 9) digits[i] = 0;
                }
                digits.push_back(0); // and a 0 at the end
                // size getting increased
                return digits;
            }
        }
        if (digits.size() == 1 && digits[digits.size()-1] == 9) { // 1 digit but is 9 then
            digits[0] = 1;
            digits.push_back(0);
            return digits;
        }
        else if(digits[digits.size()-1] == 9){
            for (int i = digits.size()-1; i >= 0; i--) {
                if (digits[i] != 9) {
                    digits[i] += 1;
                    break;
                }
                else {
                    digits[i] = 0;
                }
            }
            return digits;
        }
        else {
            digits[digits.size()-1] += 1;
            return digits;
        }
    }
};