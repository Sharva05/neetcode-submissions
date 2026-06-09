class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, distance = INT_MAX, mark = 0;
        unordered_map<char, int>fqT, fqS;

        for(char c : t) fqT[c]++;

        int need = fqT.size(), have = 0;
        for(int r = 0; r < s.length(); r++) {
            char c = s[r];
            fqS[c]++;
            if(fqS[c] == fqT[c]) have++;

            while(have == need) {
                if(r - l + 1 < distance) {
                    mark = l;
                    distance = r -  l + 1;
                }

                if(fqT[s[l]] == fqS[s[l]]) have--;
                fqS[s[l]]--; 
                l++;
            }

        }
        return distance == INT_MAX ? "" : s.substr(mark, distance);
    }
};
