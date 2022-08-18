// Link : https://leetcode.com/problems/set-matrix-zeroes/


//Most optimised  - storing result in 1st row and col of matrix 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int r =matrix.size();
    int c = matrix[0].size();
    
    bool frow= false, fcol = false;
    
    for(int i=0;i<c;i++)
        if(matrix[0][i]==0)
        {
            frow =true;
            break;
        }
    
    for(int i=0;i<r;i++)
        if(matrix[i][0]==0)
        {
            fcol =true;
            break;
        }
    
    
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0]=matrix[0][j]=0;
            }

        }
    }
    
  
      for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(matrix[i][0]==0 or matrix[0][j]==0)
            {
                matrix[i][j] =0;
            }
        }
    }
   
  if(frow)  
  {
      for(int i=0;i<c;i++){
            matrix[0][i]=0;
    }
  }
    
     
  if(fcol)  
  {
      for(int i=0;i<r;i++){
            matrix[i][0]=0;
    }
  }
    
  
        
    }
};

//optimised  
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       
    int r =matrix.size();
    int c = matrix[0].size();
    vector<bool> rows(r,0);
    vector<bool> cols(c,0);
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(matrix[i][j]==0)
            {
                rows[i]=true;
                cols[j]=true;
            }

        }
    }
    
      for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(rows[i] or cols[j])
            {
                matrix[i][j] =0;
            }
        }
    }
    
  
        
    }
};


//Brute force 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
	    int m = matrix[0].size();
	
	vector<vector<bool>> isCellZero(n,vector<bool>(m));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			
			if(matrix[i][j] == 0) {
				
				for(int k = 0; k < n; k++) {
					isCellZero[k][j] = true;
				}
				
				for(int k = 0; k < m; k++) {
					isCellZero[i][k] = true;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(isCellZero[i][j]) {
				matrix[i][j] = 0;
			}
		}
	}
        
        
    }
};

