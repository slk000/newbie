#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            switch(ch) {
                case '(':
                case '{':
                case '[':
                    st.push(ch);
                    break;
                case ')':
                    if (st.top() == '(') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                    break;

                case '}':
                    if (st.top() == '{') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                    
                case ']':
                    if (st.top() == '[') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                    break;
            }
        }
        return s.empty();
    }
};

int main() {
    cout << Solution().isValid("()") << endl;
}
