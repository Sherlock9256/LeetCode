/*
MapSum() 初始化 MapSum 对象
void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，那么原来的键值对将被替代成新的键值对。
int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/map-sum-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<string>
using namespace std;

class MapSum {
    MapSum* follower[26] = {nullptr};
    bool isLeaf = false;
    int val = 0;
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        MapSum* tmp = this;
        int ofst;
        for(int i =0;i<key.length();i++){
            ofst = key[i]-'a';
            if(tmp->follower[ofst]==nullptr){
                tmp->follower[ofst] = new MapSum();
            }
            tmp = tmp->follower[ofst];
        }
        tmp->val = val;
        tmp->isLeaf = true;
    }
    
    int sum(string prefix) {
        MapSum* tmp = this;
        int ofst;
        for(int i = 0;i<prefix.length();i++){
            ofst = prefix[i]-'a';
            tmp = tmp->follower[ofst];
            if(!tmp) return 0;
        }
        return sum(tmp);
    }

    int sum(MapSum* cur){
        int ret = cur->val;
        for(int i = 0;i<26;i++){
            if(cur->follower[i]){
                ret += sum(cur->follower[i]);
            }
        }
        return ret;
    }
};