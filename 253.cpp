#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
class Solution{
public:
    int minMeetingRooms(vector<vector<int>>& intervals){
        int ret = 0;
        int available = 0;
        queue<int> endtimes;
        endtimes.push(0);
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){
            return a[1]<b[1];
        });
        for(auto& ele:intervals){
            while(!endtimes.empty()&&ele[0]>=endtimes.front()){
                available++;
                if(available>ret){
                    ret++;
                }
                endtimes.pop();
            }
            if(available==0){
                ret++;
            }else{
                available--;
            }
            endtimes.push(ele[1]);
        }
        cout<<ret<<endl;
        return ret;
    }
};

int main(){
    vector<int> a = {7,10};
    vector<int> b = {2,4};
    vector<int> c = {15,20};
    vector<vector<int>> inter={a,b};
    Solution s;
    s.minMeetingRooms(inter);

}