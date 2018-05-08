

class RandomizedSet
{
private:
    vector<int> nums;
    unordered_map<int,int> cache;
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        srand((unsigned)time(0)));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(cache.count(val) == 1) return false;
        cache[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(cache.count(val) == 0) return false;
        int index = cache[val];
        nums[index] = nums.back();
        cache[nums[index]] = index;
        cache.erase(val);
        nums.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};
