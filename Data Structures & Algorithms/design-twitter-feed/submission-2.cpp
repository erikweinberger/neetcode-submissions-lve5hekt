struct userObj {
    int userId;
    std::vector<std::pair<int, int>> tweets;
    std::unordered_set<int> following;

    userObj() : userId(0) {}
    userObj(int id) : userId(id) {}
};

struct PostCompareTimeRecent {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
    }
};

class Twitter {
    int tweetTimer;
    std::unordered_map<int, userObj> users;

public:
   Twitter() : tweetTimer(0) {}
    
    void postTweet(int userId, int tweetId) {
        auto userIt = users.find(userId);
        if (userIt == users.end()) {
            users[userId] = userObj(userId);
            userIt = users.find(userId);
        }
        
        userIt->second.tweets.push_back({tweetTimer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        auto userIt = users.find(userId);
        if (userIt == users.end()) return {};
        userObj &user = userIt->second;

        std::vector<int> result;
        result.reserve(10);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PostCompareTimeRecent> tweets;
        for (const auto & t : user.tweets) {
            tweets.push(t);
        }

        for (const auto & followeeId : user.following) {
            auto followeeIt = users.find(followeeId);
            if (followeeIt == users.end()) continue;
            userObj &f = followeeIt->second;
            int nT = static_cast<int>(f.tweets.size());

            for (int i = nT - 1; i >= 0 && nT - i <= 10; --i) {
                tweets.push(f.tweets[i]);
            }
        }

        int i = 0;
        while (!tweets.empty() && i < 10) {
            auto tweet = tweets.top();
            if (tweet.second == result.back()) {
                tweets.pop();
                continue;
            }
            result.push_back(tweet.second);
            tweets.pop();
            ++i;
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        auto userIt = users.find(followerId);
        if (userIt == users.end()) {
            users[followerId] = userObj(followerId);
            userIt = users.find(followerId);
        }

        userIt->second.following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        auto userIt = users.find(followerId);
        if (userIt == users.end()) {
            users[followerId] = userObj(followerId);
            userIt = users.find(followerId);
        }

        userIt->second.following.erase(followeeId);
    }
};
