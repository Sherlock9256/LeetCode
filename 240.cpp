#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix,target,0,matrix.size()-1,0,matrix[0].size()-1);
    }

    bool search(vector<vector<int>>& matrix, int target,int r_begin,int r_end,int c_begin,int c_end){

        int mid,l,r;
        //row
        //lowerbound
        l=r_begin;
        r=r_end;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[mid][c_begin]<target){
                l = mid+1;
            }else if(matrix[mid][c_begin]>target){
                r = mid-1;
            }else{
                return true;
            }
        }
        r_end = r;
        //upperbound
        l=r_begin;
        r=r_end;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[mid][c_end]<target){
                l = mid+1;
            }else if(matrix[mid][c_end]>target){
                r = mid-1;
            }else{
                return true;
            }
        }
        r_begin = l;
        if(r_begin>r_end) return false;

        //column
        //lowerbound
        l=c_begin;
        r=c_end;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[r_begin][mid]<target){
                l = mid+1;
            }else if(matrix[r_begin][mid]>target){
                r = mid-1;
            }else{
                return true;
            }
        }
        c_end = r;
        //upperbound
        l=c_begin;
        r=c_end;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[r_end][mid]<target){
                l = mid+1;
            }else if(matrix[r_end][mid]>target){
                r = mid-1;
            }else{
                return true;
            }
        }
        c_begin = l;
        if(c_begin>c_end) return false;
        return search(matrix,target,r_begin,r_end,c_begin,c_end);
    }
};