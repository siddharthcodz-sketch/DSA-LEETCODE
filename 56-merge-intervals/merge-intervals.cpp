class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < n; i++) {

            if (intervals[i][0] <= end) {       //overlapp
                end = max(end, intervals[i][1]);
            }
            else {
                // no overlap
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        //last case handle
        result.push_back({start, end});

        return result;
    }
};