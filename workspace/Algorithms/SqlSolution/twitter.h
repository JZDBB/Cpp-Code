#pragma once
#include"solution.h"

class Twitter {
private:
	int recentMax, time;
	struct Node {
		unordered_set<int> followee;
		vector<pair<int,int>> tweet;
	};
	unordered_map<int, Node> users;

public:
	/** Initialize your data structure here. */
	Twitter() {
		recentMax = 10;
		users.clear();
		time = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		if (users.find(userId) == users.end()) {
			users[userId].followee.clear();
			users[userId].tweet.clear();
		}
		users[userId].tweet.push_back(pair<int, int>(time, tweetId));
		time++;
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<int> res;
		if (users.find(userId) == users.end()) return{};
		int toptime = time;
		int newsid;
		for (int i = 0; i < recentMax; i++) {
			int recent = -1;
			for (int key : users[userId].followee) {
				int size = users[key].tweet.size();
				for (int j = size - 1; j >= 0; j--) {
					int tweetTime = users[key].tweet[j].first;
					if (tweetTime < toptime && tweetTime > recent) {
						recent = users[key].tweet[j].first;
						newsid = users[key].tweet[j].second;
						break;
					}
				}
			}
			int size = users[userId].tweet.size();
			for (int j = size - 1; j >= 0; j--) {
				int tweetTime = users[userId].tweet[j].first;
				if (tweetTime < toptime && tweetTime > recent) {
					recent = users[userId].tweet[j].first;
					newsid = users[userId].tweet[j].second;
					break;
				}
			}
			if (recent == -1) break;
			toptime = recent;
			res.push_back(newsid);
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		users[followerId].followee.insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		users[followerId].followee.erase(followeeId);
	}
};