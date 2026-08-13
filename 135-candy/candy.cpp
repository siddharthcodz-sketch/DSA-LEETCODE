class Solution {
public:
    int candy(vector<int>& arr) {
         int n = arr.size();
        int i=1;
        int sum = n;                     //compair (i to i-1) as per current scene n all
        while(i<n){
            if(i<n && arr[i]==arr[i-1]){
                i++;
                continue;
            }

            int up = 0;
            while(i<n && arr[i-1]<arr[i]){
                up++;                                            // 1 2 1
                sum += up;   
                i++;
            }

            int down =0;
            while(i<n && arr[i-1]>arr[i]){
                down++;
                sum += down;
                i++;
            }
            sum -= min(up,down);
            // i++;
        }
        return sum;
    }
};