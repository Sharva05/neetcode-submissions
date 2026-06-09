class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b;
        for(const string& c : tokens) {
            if(c == "+") {
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a + b);
            }
            else if(c == "-") {
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a - b);
            }
            else if(c == "*") {
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a * b);
            }
            else if(c == "/") {
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a / b);
            }
            else {
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};