#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
using namespace std;

// class Solution1 {
// public:
//     map<int,pair<char,int>> m;
//     Solution1 (){
//         pair<char,int> p('a',3);
//         m[2] = p;
//         p.first = 'd';p.second = 3;
//         m[3] = p;
//         p.first = 'g';p.second = 3;
//         m[4] = p;
//         p.first = 'j';p.second = 3;
//         m[5] = p;
//         p.first = 'm';p.second = 3;
//         m[6] = p;
//         p.first = 'p';p.second = 4;
//         m[7] = p;
//         p.first = 't';p.second = 3;
//         m[8] = p;
//         p.first = 'w';p.second = 4;
//         m[9] = p;
//     }
//     vector<string> letterCombinations(string digits) {
//         vector<string> ret;
//         if(digits.length()!=0){
//             char chr = m[digits[0]-'0'].first;
//             int cnt = m[digits[0]-'0'].second;
//             vector<string> sub_ret = letterCombinations(digits.substr(1));
//             if(sub_ret.size()!=0){
//                 string sub_ret_str;
//                 for (int i = 0;i<sub_ret.size();i++){
//                     sub_ret_str = sub_ret[i];
//                     for(int j = 0;j<cnt;j++){
//                         ret.push_back((char)(chr+j)+sub_ret_str);
//                     }
//                 }
//             }else{
//                 string tmp = "";
//                 for(int j = 0;j<cnt;j++){
//                     ret.push_back((char)(chr+j)+tmp);
//                 }
//             }
//         }
//         return ret;
//     }
// };
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }
        map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string>& combinations, const map<char, string>& phoneMap, const string& digits, int index, string& combination) {
        if (index == digits.length()) {
            combinations.push_back(combination);
        } else {
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for (const char& letter: letters) {
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};


int main(){
    Solution s;
    s.letterCombinations("23");
}