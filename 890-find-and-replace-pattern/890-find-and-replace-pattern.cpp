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
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        vector<int> ptn = find_pat(pattern);
        int n = words.size();
        for(int i = 0;i<n;i++){
            if(find_pat(words[i]) == ptn){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};