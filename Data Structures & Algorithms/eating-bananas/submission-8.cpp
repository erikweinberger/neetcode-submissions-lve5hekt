class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upperBound = *std::max_element(piles.begin(), piles.end());
        int lowerBound = 1;

        int minEatSpeed = upperBound;
        while (lowerBound <= upperBound) {
            int midPointEatingSpeed = (upperBound + lowerBound) / 2;
            
            int timeToEatPilesIteration = 0;
            for (auto pile : piles) {
                int timeToEatPile = static_cast<int>(std::ceil(static_cast<double>(pile) / midPointEatingSpeed));
                timeToEatPilesIteration += timeToEatPile;
            }
            if (timeToEatPilesIteration <= h) {
                upperBound = midPointEatingSpeed - 1;
                minEatSpeed = midPointEatingSpeed;
            }
            else {
                lowerBound = midPointEatingSpeed + 1;
            }
        }

        return minEatSpeed;
        
    }
};
