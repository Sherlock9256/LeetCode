#include<vector>
using namespace std;
class Solution {
    vector<int> ret;
    int m ;
    int n ;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m==0)return ret;
        n = matrix[0].size();
        if(n==0)return ret;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        help(matrix,visited,0,0,1);
        return ret;
    }
    bool help(vector<vector<int>>& matrix,vector<vector<bool>>& visited,int i ,int j,int mod){
        if(0<=i&&i<m&&0<=j&&j<n&&!visited[i][j]){
            visited[i][j]=true;
            ret.push_back(matrix[i][j]);
            bool tmp;
            switch (mod)
            {
            case 1:
                tmp = help(matrix,visited,i,j+1,1);
                if(!tmp){
                    tmp = help(matrix,visited,i+1,j,2);
                }
                break;
            case 2:
                tmp = help(matrix,visited,i+1,j,2);
                if(!tmp){
                    tmp = help(matrix,visited,i,j-1,3);
                }
                break;
            case 3:
                tmp = help(matrix,visited,i,j-1,3);
                if(!tmp){
                    tmp = help(matrix,visited,i-1,j,4);
                }
                break;
            case 4:
                tmp = help(matrix,visited,i-1,j,4);
                if(!tmp){
                    tmp = help(matrix,visited,i,j+1,1);
                }
                break;      
            }
            return true;
        }else{
            return false;
        }
    }
};
class Solution {
    vector<int> ret;
    int i,j;
    int up,down;
    int left,right;
    int cnt = 0;
    int tot;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        i=0;j=0;
        up=0;left=-1;
        down = matrix.size()-1;
        right = matrix[0].size()-1;
        tot = (down+1)*(right+1);
        help(matrix);
        return ret;
    }
    void help(vector<vector<int>>& matrix){
        ret.push_back(matrix[i][j]);
        cnt++;
        if(cnt==tot){
            return;
        }

        if(i==up&&j<right){
            j++;
            if(j==right)left++;
        }else if(i<down&&j==right){
            i++;
            if(i==down)up++;
        }else if(i==down&&j>left){
            j--;
            if(j==0)right--;
        }else if(i>up&&j==left){
            i--;
            if(i==up)down--;
        }
        help(matrix);

    }
};