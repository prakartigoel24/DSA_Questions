//Link: https://leetcode.com/problems/fizz-buzz/

//OPTIMISED SOLUTION(using for loops)

class Solution {
public:
    vector<string>
        fizzBuzz(int n) {
        
     vector<string> ans(n);
        
    for(int i=1;i<=n;i++)
    {
        ans[i-1]=to_string(i);
    }
    for(int i=2;i<n;i+=3)
    {
        ans[i]="Fizz";
    }
    for(int i=4;i<n;i+=5)
    {
        ans[i]="Buzz";
    }
    for(int i=14;i<n;i+=15)
    {
        ans[i]="FizzBuzz";
    }
       return ans; 
    }
};



//************************************************************************************************************************

//OPTIMISED SOLUTION(using hashmap)

class Solution {
public:
    vector<string>
        fizzBuzz(int n) {
        
     vector<string> ans;
     map<int,string> mp;
        
        mp[3]="Fizz";
        mp[5]="Buzz";
        
        for(int i=1;i<=n;i++)
        {
            string str="";
            
            for(auto it:mp)
            {
                if(i% it.first ==0)
                {
                    str+=it.second;
                }
            }
            
            if(str.empty())
                str=to_string(i);
            
            
            ans.push_back(str);
        }
        
        return ans;
    }
};


// *************************************************************************************************************************************

//less optimised 

class Solution {
public:
    vector<string>
        fizzBuzz(int n) {
        
        vector<string> answer;
        
        
        for(int i=1;i<=n;i++)
        {
            string str="";
            
             if(i%3==0)
            {
            
                 str+="Fizz";

            }
            if(i%5==0)
            {
                   str+="Buzz";

            }
            if(str.empty()) 
                str= to_string(i);
            
            
            answer.push_back(str);
        }
        
        return answer;
        
    }
};



