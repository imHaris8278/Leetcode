var Twitter = function() 
{
    this.tweets = [];
    this.userTweets = new Map();
    this.following = new Map();
};

/** 
 * @param {number} userId 
 * @param {number} tweetId
 * @return {void}
 */
Twitter.prototype.postTweet = function(userId, tweetId) 
{
    this.tweets.push({userId: userId, tweetId: tweetId});

    if (!this.userTweets.has(userId)) 
    {
        this.userTweets.set(userId, []);
    }

    this.userTweets.get(userId).push(tweetId);
};

/** 
 * @param {number} userId
 * @return {number[]}
 */
Twitter.prototype.getNewsFeed = function(userId) 
{
    let feed = [];
    let following = this.following.get(userId) || new Set();
    following.add(userId);

    for (let i = this.tweets.length - 1; i >= 0 && feed.length < 10; i--) 
    {
        let tweet = this.tweets[i];
    
        if (following.has(tweet.userId)) 
        {
            feed.push(tweet.tweetId);
        }
    }

    return feed;
};

/** 
 * @param {number} followerId 
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.follow = function(followerId, followeeId) 
{
    if (!this.following.has(followerId)) 
    {
        this.following.set(followerId, new Set());
    }
    
    this.following.get(followerId).add(followeeId);
};

/** 
 * @param {number} followerId 
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.unfollow = function(followerId, followeeId) 
{
    if (this.following.has(followerId)) 
    {
        this.following.get(followerId).delete(followeeId);
    }
};