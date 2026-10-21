class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = max(0, k - m); i <= min(k, n); i++) {
            vector<int> a, b;

            // Select i digits from nums1
            int drop = n - i;
            for (int x : nums1) {
                while (!a.empty() && drop > 0 && a.back() < x) {
                    a.pop_back();
                    drop--;
                }
                a.push_back(x);
            }
            a.resize(i);

            // Select k-i digits from nums2
            drop = m - (k - i);
            for (int x : nums2) {
                while (!b.empty() && drop > 0 && b.back() < x) {
                    b.pop_back();
                    drop--;
                }
                b.push_back(x);
            }
            b.resize(k - i);

            // Merge both sequences to form the maximum number
            vector<int> cur;
            int p = 0, q = 0;

            while (p < a.size() || q < b.size()) {
                if (lexicographical_compare(
                    a.begin() + p, a.end(),
                    b.begin() + q, b.end())) {
                    cur.push_back(b[q++]);
                } else {
                    cur.push_back(a[p++]);
                }
            }

            // Keep the lexicographically larger result
            if (lexicographical_compare(
                ans.begin(), ans.end(),
                cur.begin(), cur.end())) {
                ans = cur;
            }
        }

        return ans;
    }
};