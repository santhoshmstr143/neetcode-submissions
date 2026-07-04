/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1;
        long long r = n;
        while(l<=r)
        {
            long long mid = l +(r-l)/2;
            int t = guess(mid);
            if(t==0)
            {
                return mid;
            }
            else if(t==-1)
            {
                r = mid -1;
            }
            else
            {
                l= mid+1;
            }
        }
        return -1;
    }
};