// LINK :https://leetcode.com/problems/4sum/

// Generalized solution for K-SUM using recursion (Optimal)
class Solution {
public:
    vector<vector<int>> Ksum(vector<int>& arr, long long target, int k, int idx)
    {
        
        if(k==1 and find(arr.begin(),arr.end(),target)!= arr.end())
        {
            vector<vector<int>> ans;
            ans.push_back({int(target)});
            return ans;
        }
        else if(k==2)
        {
            vector<vector<int>> ans;
            int l = idx,r = arr.size()-1;
            
            while(l<r)
            {
                if(arr[l]+arr[r]==target)
                {
                    vector<int> v;
                    v.push_back(arr[l]);
                    v.push_back(arr[r]);
                    ans.push_back(v);
                    
                    while(l<r and arr[l]==arr[l+1]) l++;
                    while(l<r and arr[r]==arr[r-1]) r--;
                    l++, r--;
                }
                else if(arr[l]+arr[r] < target)
                    l++;
                else
                    r--;
            }
            return ans;
        }
        else
        {
            vector<vector<int>> ans;
            for(int i=idx;i<=arr.size()-k;i++)
            {
                int first = arr[i];
                vector<vector<int>> temp = Ksum(arr, target - first + 0LL, k-1, i+1);
                for(auto it: temp)
                {
                    vector<int> v;
                    v.push_back(first);
                    for(auto itt: it)
                    {
                       v.push_back(itt);
                    }
                    ans.push_back(v);
                }
                
                while(i<arr.size()-1 and arr[i]==arr[i+1]) i++;
            }
            
            return ans;
        }
     }
    
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int k = 4;  // change the value of K here.
        if(n<= k-1) return {};
        
        return Ksum(arr,target,k,0);
        
    }
};



// Using 2 Pointer approach - (Enclosing 3sum with one more loop)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        
        int n= arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int l = j+1 , r = n-1;
                
                while(l<r)
                {
                    long long tar = 0LL + target - arr[i] -arr[j];
                    
                    if(arr[l] + arr[r] ==tar)
                    {
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[l]);
                        v.push_back(arr[r]);
                        ans.push_back(v);
                        
                        while(l<r and arr[l]==arr[l+1])
                            l++;
                        while(l<r and arr[r]==arr[r-1])
                            r--;
                        
                        l++;
                        r--;
                        
                    }
                    else if(arr[l] + arr[r] < tar)
                    {
                        l++;
                    }
                    else
                        r--;
                }
                
                while(j+1 < n and arr[j+1] == arr[j]) ++j;
                
            }
            
             while(i < n-1 and arr[i+1] == arr[i]) ++i;

        }
        
        return ans;
    }
};


