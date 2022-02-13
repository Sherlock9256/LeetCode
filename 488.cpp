#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<stack>
#include<vector>
using namespace std;
class Solutionmy {
public:
    int findMinStep(string board, string hand) {
        vector<int> cnts;
        search(board,hand,0,cnts);
        int min_ = 20;
        if(cnts.size()!=0){
            for(int i = 0;i<cnts.size();i++){
                if(min_>cnts[i]){
                    min_ = cnts[i];
                }
            }
        }else{
            min_=-1;
        }

        return min_;
    }   
    void search(string board,string hand,int cnt,vector<int>& cnts){
        cout<<board<<" "<<board.length()<<" "<<hand<<" "<<hand.length()<<" "<<cnt<<endl;
        bool find = false;
        int ___ = board.length()-1;
        for(int i = 0;i<___;i++){
            if(board[i]==board[i+1]){
                for(int j = 0;j<hand.size();j++){
                    if(hand[j]==board[i]){
                        if(hand[j]=='B'){
                           int qweqweqwe = 1;
                        }
                        if(hand[j]=='R'){
                           int asdc= 3;
                        }
                        find = true;
                        int left = i;
                        int right = i+1;
                        while(left-1>=0&&right+1<board.size()&&board[left-1]==board[right+1]){
                            left--;
                            right++;
                            bool find = false;
                            if(left-1>=0&&board[left]==board[left-1]){
                                left --;
                                find = true;
                            }
                            if(right+1<board.length()&&board[right+1]==board[right]){
                                right ++;
                                find = true;
                            }
                            if(!find){
                                left++;
                                right--;
                                break;
                            }
                        }
                        string tmp1 = board;
                        string tmp2 = hand;
                        search(tmp1.erase(left,right-left+1),tmp2.erase(j,1),cnt+1,cnts);
                        cout<<"ret"<<endl;
                        cout<<board<<" "<<board.length()<<" "<<hand<<" "<<hand.length()<<" "<<cnt<<endl;
                        break;
                    }
                }
            }
        }
        if(!find&&board.length()==0){
            cnts.push_back(cnt);
        }
        if(!find&&board.length()==1){
            int tmp = 0;
            for(int i = 0;i<hand.length();i++){
                if(hand[i]==board[0]){
                    tmp++;
                    if(tmp==2){
                        cnts.push_back(cnt+2);
                        break;
                    }
                }
            }
        }
    }
};

class Solution {
    int ans, used;
    map<char, int> rem;
    stack<pair<char, int>> st;

    void dfs(int pos, string &board) {
        if (used >= ans)
            return;

        if (pos == board.size()) {
            if (st.empty())
                ans = used;
            return;
        }
        
        // 将pos位置的小球加入
        if (!st.empty() && st.top().first == board[pos]) {
            st.top().second++;
        } else {
            st.emplace(board[pos], 1);
        }

        if (st.top().second >= 3) {
            if (pos + 1 == board.size() || board[pos + 1] != board[pos]) {
            // 后面没有相同颜色的球，可以直接消去
                auto tmp = st.top();    
                st.pop();
                dfs(pos + 1, board);
                st.push(tmp);
            } else {
            // 后面有相同颜色的球，必须插入与当前位置不同色的小球进行分隔后，才能将当前积累的小球消去；否则必须和后面的同色球一起消去。
                auto tmp = st.top(); // 维护现场
                st.pop(); // 消去当前积累的同色小球

                for (auto [ch, num] : rem) {
                    if (ch == board[pos])
                        continue;
                    for (int j = 1; j <= min(3, num); ++j) {
                        rem[ch] -= j;
                        used += j;

                        // 加入j个小球
                        if (!st.empty() && st.top().first == ch) {
                            st.top().second += j;
                        } else {
                            st.emplace(ch, j);
                        }

                        if (st.top().second >= 3) { // 插入的异色球和之前的球累加达到了三个
                            auto tmp2 = st.top(); // 维护现场
                            st.pop(); // 消去同色球
                            dfs(pos + 1, board);
                            st.push(tmp2); // 还原现场
                        } else {
                            dfs(pos + 1, board);
                        }

                        // 还原现场
                        if (st.top().second > j) {
                            st.top().second -= j;
                        } else {
                            st.pop();
                        }
                        used -= j;
                        rem[ch] += j;
                    }
                }

                st.push(tmp); // 还原现场
            }
        }
        
        // 插入与当前位置同色的小球
        if (rem[board[pos]] >= 1 && (pos + 1 == board.size() || board[pos + 1] != board[pos])) {
            int lim = rem[board[pos]];
            for (int i = 1; i <= min(2, lim); ++i) {
                // 加入i个同色小球
                rem[board[pos]] -= i;
                used += i;
                st.top().second += i;
                if (st.top().second >= 3) { // 累积同色球达到三个
                    auto tmp = st.top(); // 维护现场
                    st.pop(); // 消去同色球
                    dfs(pos + 1, board);
                    st.push(tmp); // 还原现场
                } else {
                    dfs(pos + 1, board);
                }

                // 还原现场
                st.top().second -= i;
                used -= i;
                rem[board[pos]] += i;
            }
        }
        
        // 不额外插入小球的情形
        // 1. 当前颜色小球不满三个
        // 2. 当前颜色小球满三个，但当前小球和下一小球同色，这说明初始情形为XX...XX，之后中间的小球被消去，从而形成了XXXX，这种情况是允许的。
        if (st.top().second < 3 || (st.top().second == 3 && pos + 1 < board.size() && board[pos] == board[pos + 1]))
            dfs(pos + 1, board);

        // 还原现场
        if (st.top().second == 1) {
            st.pop();
        } else {
            st.top().second--;
        }
    }
public:
    int findMinStep(string board, string hand) {
        for (char ch : hand)
            rem[ch]++;

        ans = 1e9;
        used = 0;
        dfs(0, board);
        return ans == 1e9 ? -1 : ans;
    }
};

int main(){
    string board = "WWRRBBWW";
    string hand = "WRBRW";
    // cout<<hand;
    // string hand = "";
    // int p = hand.length()-1;
    // cout<<p;
    // string p = hand.erase(1,2);
    // cout<<p.length()<<endl;
    // cout<<p<<endl;
    Solution s;
    s.findMinStep(board,hand);
    return 0;
}