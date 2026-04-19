class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        std::vector<std::pair<int, int>> posSpeedVector;
        posSpeedVector.reserve(n);

        for (int i = 0; i < n; ++i) {
            posSpeedVector.push_back({position[i], speed[i]});
        }
        std::sort(posSpeedVector.begin(), posSpeedVector.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; 
        });

        int numFleets = 0;
        std::vector<float> arrivalTimes;
        for (int i = 0; i < n; ++i) {
            float arrivalTime = (target - posSpeedVector[i].first) / static_cast<double>(posSpeedVector[i].second);
            if (arrivalTimes.empty() || arrivalTime > arrivalTimes.back()) {
                arrivalTimes.push_back(arrivalTime);  
            }
        }

        return arrivalTimes.size();


    }
};
