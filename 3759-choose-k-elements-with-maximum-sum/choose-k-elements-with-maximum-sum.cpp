class Solution {
public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
               int n = nums1.size();
    vector<long long> ans(n,0);
        vector<pair<int,int>>arr(n,{0,0});
        for(int i=0;i<n;i++){
            arr[i] = {nums1[i],i};
        }

    
        sort(arr.begin(),arr.end());



        vector<pair<pair<int,int>,int>> brr(n,{{0,0},0});  
        for(int i =0;i<n;i++){
            brr[i]= {{arr[i].first,arr[i].second},nums2[arr[i].second]};
        }       

        
        long long sum = 0;
        priority_queue<int, vector<int>,greater<int>>pq;

        int i = 0;
        while(i < n){
            int j = i;
            while(j < n && brr[j].first.first == brr[i].first.first){
                j++;
            }
            // Give answers first
            for(int x=i; x<j; x++){
                ans[brr[x].first.second] = sum;
            }

            // Now insert all elements of this value
            for(int x=i; x<j; x++){
                pq.push(brr[x].second);
                sum += brr[x].second;

                if(pq.size() > k){
                    sum -= pq.top();
                    pq.pop();
                }
            }
            i = j;
        }
        return ans;
        }
};