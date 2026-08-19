// Last updated: 19/08/2026, 16:02:35
class Twitter {
    int cnt;
    unordered_map<int,vector<pair<int,int>>> tweetmap;
    unordered_map<int,unordered_set<int>> followermap;
public:
    Twitter() {
        cnt = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({cnt,tweetId});
        ++cnt;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<array<int,4>> pq;
        //ensure user follow himself
        followermap[userId].insert(userId);

        for(int followeeId : followermap[userId]){
            if(tweetmap.count(followeeId)){
                int i = tweetmap[followeeId].size() - 1;
                auto &tweet = tweetmap[followeeId][i];
                pq.push({tweet.first,tweet.second,followeeId,i-1});
            }
        }
        while(!pq.empty() && ans.size() < 10){
            auto data = pq.top();
            pq.pop();
            ans.push_back(data[1]);
            if(data[3] >= 0){ // still tweets left from this followee
            auto &tweet = tweetmap[data[2]][data[3]];
            pq.push({tweet.first,tweet.second,data[2],data[3] - 1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        followermap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        if(followermap[followerId].count(followeeId)){
            followermap[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */