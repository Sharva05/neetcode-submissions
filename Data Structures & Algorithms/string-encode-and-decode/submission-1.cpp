class Solution {
public:

    string encode(vector<string>& strs) {
        string encd;
        for(string s: strs){
            encd+= s + "#:";
        }
        return encd;
    }

    vector<string> decode(string s) {
        vector<string>vec;
        string temp;
        for(int i = 0; i< s.length(); i++){
            if( s[i]== '#' && s[i+1]==':'){
                vec.push_back(temp);
                temp= "";
                i++;
            }
            else{
                temp+= s[i];
            }  
        }
        return vec;
    }
};
