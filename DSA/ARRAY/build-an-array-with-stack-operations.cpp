//LINK : https://leetcode.com/problems/build-an-array-with-stack-operations/

//using stack

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> str; 
        stack<int> st;
        
        int k = 0;
        for(int i=1;i<=n;i++)
        {
            st.push(i);
            str.push_back("Push");
            
            if(i != target[k])
            {
                st.pop();
                str.push_back("Pop");
            }
            else
                k++;
            
            if(target.size()==st.size())
                break;
        }

        return str;
        
    }
};

// without stack

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> str; 
            
        int c=0;
        int k = 0;
        for(int i=1;i<=n;i++)
        {
            str.push_back("Push");
            c++;
            
            if(i != target[k])
            {
                str.push_back("Pop");
                c--;
            }
            else
                k++;
            
            if(target.size()==c)
                break;
        }

        return str;
        
    }
};
