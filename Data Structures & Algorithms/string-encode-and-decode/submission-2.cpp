class Solution {
public:

    string encode(vector<string>& strs) {
        string encd;
        for(string s: strs){
            encd+= to_string(s.length()) + '@' + s ;
        }
        return encd;
    }

    vector<string> decode(string s) {
        vector<string>vec;
        int left =0;
        while(left < s.length()){
            string lenStr="";
            while(s[left]!='@'){
                lenStr += s[left++];
            }
            left++;
            int len=stoi(lenStr);
            vec.push_back(s.substr(left, len));
            left+=len;
        }
        return vec;
    }
};
