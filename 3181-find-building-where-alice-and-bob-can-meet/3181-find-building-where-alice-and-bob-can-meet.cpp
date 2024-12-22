class Solution {
public:
    int binarySearch(int height, vector<pair<int, int>>& st) {
        int l = 0, r = st.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (st[mid].first > height) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<pair<int, int>> st;
        vector<int> answer(queries.size(), -1);
        vector<vector<pair<int, int>>> newQueries(heights.size());

        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b);
            answer[i] = (heights[b] > heights[a] || a == b) ? b : -1;
            if (answer[i] == -1) newQueries[b].push_back({heights[a], i});
        }

        for (int i = heights.size() - 1; i >= 0; i--) {
            for (auto& [h, idx] : newQueries[i]) {
                int pos = binarySearch(h, st);
                if (pos != -1) answer[idx] = st[pos].second;
            }
            while (!st.empty() && st.back().first <= heights[i])
                st.pop_back();
            st.push_back({heights[i], i});
        }

        return answer;
    }
};