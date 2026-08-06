class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    int m = g.size();
    int n = s.size();
    if(n==0|| m==0 ) return 0;
    int ans =0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int st = 0;
    int c = 0;
    while(c<n && st<m){
        if(g[st] <= s[c]){
            st++;
            ans++;
        }
        c++;
    }
    return ans;
    }
};