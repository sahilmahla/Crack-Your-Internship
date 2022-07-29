class Solution {
public:
    vector<int> find_pat(string word){
        vector<int> res;
        int idx = 0;
        
        unordered_map<char,int> s;
        int n = word.size();
        for(int i = 0;i<n;i++){
            if(s.find(word[i]) == s.end()){
                s.insert({word[i],idx++});
                res.push_back(s[word[i]]);
            }else{
                 res.push_back(s[word[i]]);
            }
        }
        return res;
    }
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        return find_pat(t) == find_pat(s);
    }
};