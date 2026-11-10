class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();

        map<tuple<int, int, long long>, vector<pair<int, int>>> mp;

        double ans = DBL_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int mx = x1 + x2;
                int my = y1 + y2;

                long long dx = x2 - x1;
                long long dy = y2 - y1;

                long long dist = dx * dx + dy * dy;

                auto key = make_tuple(mx, my, dist);

                for (auto p : mp[key]) {
                    int x3 = points[p.first][0];
                    int y3 = points[p.first][1];

                    long long ax = x2 - x1;
                    long long ay = y2 - y1;

                    long long bx = x3 - x1;
                    long long by = y3 - y1;

                    double area = abs(ax * by - ay * bx);

                    ans = min(ans, area);
                }

                mp[key].push_back({i, j});
            }
        }

        return ans == DBL_MAX ? 0.0 : ans;
    }
};