// LINK : https://leetcode.com/problems/two-furthest-houses-with-different-colors/

//Greedy solution
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int n = colors.size();
        int maxi=0, mx=0;        
        for(int i=0;i<n;i++)
        {
            if(colors[0]!=colors[i])
            {
                maxi=max(maxi, i);
            }
            
            if(colors[n-1] != colors[i])
            {
                mx=max(mx, abs(n-1-i));
            }
        }

        return max(maxi, mx);
        
    }
};

// Brute force 
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int n = colors.size();
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(colors[i]!=colors[j])
                {
                    maxi=max(maxi , abs(i-j));
                }
            }
        }
        
        return maxi;
        
        
    }
};
