// LINK : https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
        int n =arr.size();
        int indx, greaterindx; 
         
        for(int i=n-2;i>=0;i--)  //Find first point of decrease from back. (let indx)
        {
            if(arr[i] < arr[i+1])
            {
                indx = i;
                break;
            }
        }
         
        if(indx < 0)    // if point of decrease i.e. (indx < 0) then reverse array. 
        {
            reverse(arr.begin(), arr.end());  // -> ANS array
        }
        else
        {
            for(int i=n-1;i>=0;i--)  // Find greater element than indx from back.
            {
                if(arr[i] > arr[indx])
                {
                    greaterindx = i;
                    break;
                }
            }

            swap(arr[indx], arr[greaterindx]);  // Swap both indices
 
            reverse(arr.begin()+indx+1, arr.end());  // Reverse array from the right of point of decrease (indx) to end. -> ANS array
        }
        
    }
};
