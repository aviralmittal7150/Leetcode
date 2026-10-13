class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string dir = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (dir == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else if (dir != "" && dir != ".") {
                    st.push(dir);
                }

                dir = "";
            }
            else {
                dir += path[i];
            }
        }

        string result = "";

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};