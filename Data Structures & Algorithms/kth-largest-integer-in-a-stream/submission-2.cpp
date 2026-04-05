class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int m_k;

public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > m_k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
