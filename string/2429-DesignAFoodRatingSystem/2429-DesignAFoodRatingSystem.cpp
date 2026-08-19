// Last updated: 19/08/2026, 15:31:47
class FoodRatings {
 struct FoodInfo {
        string cuisine;
        int rating;
    };
    
    
    struct Compare {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first; 
            return a.second < b.second; 
        }
    };

    unordered_map<string, FoodInfo> foodMap; 
    unordered_map<string, set<pair<int,string>, Compare>> cuisineMap; 
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string f = foods[i], c = cuisines[i];
            int r = ratings[i];
            foodMap[f] = {c, r};
            cuisineMap[c].insert({r, f});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& info = foodMap[food];
        string cuisine = info.cuisine;
        int oldRating = info.rating;
        
        cuisineMap[cuisine].erase({oldRating, food});
        
        cuisineMap[cuisine].insert({newRating, food});
        
        info.rating = newRating;
    }
    
    string highestRated(string cuisine) {
         return cuisineMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */