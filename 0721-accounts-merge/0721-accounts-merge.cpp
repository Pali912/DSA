class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> graph;

        // Build graph: emails belonging to the same account are connected
        for (auto &acc : accounts) {
            string name = acc[0];

            for (int i = 1; i < acc.size(); i++) {
                emailToName[acc[i]] = name;

                graph[acc[i]].push_back(acc[1]);
                graph[acc[1]].push_back(acc[i]);
            }
        }

        unordered_set<string> visited;
        vector<vector<string>> result;

        // DFS to collect connected emails
        for (auto &it : graph) {
            string email = it.first;

            if (visited.count(email)) continue;

            vector<string> merged;
            stack<string> st;
            st.push(email);
            visited.insert(email);

            while (!st.empty()) {
                string curr = st.top();
                st.pop();
                merged.push_back(curr);

                for (auto &next : graph[curr]) {
                    if (!visited.count(next)) {
                        visited.insert(next);
                        st.push(next);
                    }
                }
            }

            sort(merged.begin(), merged.end());

            vector<string> account;
            account.push_back(emailToName[email]);

            for (auto &e : merged) {
                account.push_back(e);
            }

            result.push_back(account);
        }

        return result;
    }
};