class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false; 
        int nIters = hand.size() / groupSize;
        std::unordered_map<int, int> numberCount(hand.size());
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        int minNum = 1000;
        for (const auto &num : hand) {
            numberCount[num] += 1;
            minNum = std::min(minNum, num);
            min_heap.push(num);
        }

        bool replaceMin = false;
        for (int i{0}; i < nIters; ++i) {
            if (numberCount[minNum] == 0) minNum = min_heap.top();
            int newMin = minNum;
            for (int n{minNum}; n < minNum + groupSize; ++n) {
                if (numberCount[n] == 0) {
                    return false;
                }
                min_heap.pop();
                numberCount[n]--;
                if (replaceMin) {
                    newMin = n;
                    replaceMin = false;
                }
                if (numberCount[newMin] == 0) replaceMin = true;
            }
            minNum = newMin;
        }

        return true;
    }
};
