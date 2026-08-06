class MedianFinder {
    private:    
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int> >minHeap;
        int size;
    public:
        MedianFinder() {
            size=0;
        }
        
        void addNum(int num) {
            if(maxHeap.empty() || num <= maxHeap.top())
                maxHeap.push(num);
            else
                minHeap.push(num);

            // Balance
            if(maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            if(minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }        
        double findMedian() {
            if(maxHeap.size() == minHeap.size())
                return (maxHeap.top() + minHeap.top()) / 2.0;
            return maxHeap.top();
        }
};

    /**
    * Your MedianFinder object will be instantiated and called as such:
    * MedianFinder* obj = new MedianFinder();
    * obj->addNum(num);
    * double param_2 = obj->findMedian();
    */