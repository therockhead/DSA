// @uthor: asif

// Problem: 69. Sqrt(x)
// return a round int square root
// without using sqrt() or any builtin  funcs

class Solution {
    public int mySqrt(int x) { // used binary search
        if (x < 2) return x;
        else {
            // another approach
            // think
            double y = x;
            double z = (y + (x/y))/2;

            while(Math.abs(y-z) >= 0.00001) {
                y = z;
                z = (y+(x/y)) / 2;
            }
            return (int) z;
        }
        
    }
}