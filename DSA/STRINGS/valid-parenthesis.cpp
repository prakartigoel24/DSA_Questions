//LINK: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        if (s.length()==1)
        {
            return false;
        }
        
        for(char c: s)
        {
            switch(c){
                    
                case '(':
                case '[':
                case '{': st.push(c); break;
                    
                case ')':
                    if(st.empty() || st.top()!='(' )  return false;
                     else st.pop(); break;
                case ']':
                    if(st.empty()||st.top()!='[') return false;
                    else st.pop(); break;;
                case '}':
                    if(  st.empty() || st.top()!='{' ) return false;
                    else st.pop(); break;
  
            }

            
        }
          return st.empty(); 
            
    }
};
