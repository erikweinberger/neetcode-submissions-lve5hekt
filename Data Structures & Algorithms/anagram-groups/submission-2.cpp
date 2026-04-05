#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <functional> // for std::hash
#include <cstddef>    // for size_t

template <size_t N>
struct ArrayHasher {
    size_t operator()(const std::array<int, N>& arr) const noexcept {
        size_t h = 0;
        for (int v : arr) {
            h ^= static_cast<size_t>(std::hash<int>{}(v) + 0x9e3779b9
                                     + (h << 6) + (h >> 2));
        }
        return h;
    }
};

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> result;

        std::unordered_map<std::array<int, 26>, std::vector<std::string>, ArrayHasher<26>> tempMap;

        for (const std::string &str : strs) {
            std::array<int, 26> tempArray{};
            for (char c : str) {
                // assume lowercase a-z; if not, adjust accordingly
                tempArray[static_cast<size_t>(c - 'a')] += 1;
            }
            tempMap[tempArray].push_back(str);
        }

        result.reserve(tempMap.size());
        for (auto &pair : tempMap) {
            result.push_back(std::move(pair.second));
        }

        return result;
    }
};
