// Last updated: 19/08/2026, 15:35:38
class MovieRentingSystem {
    // Map to store price for (shop, movie)
    unordered_map<long long, int> priceMap;
    
    // Heap for unrented movies per movieId
    unordered_map<int, set<pair<int,int>>> unrented; // movie -> { (price, shop) }
    
    // Heap for rented movies
    set<tuple<int,int,int>> rented; // (price, shop, movie)
    
    int n;
    
    long long encode(int shop, int movie) {
        return ((long long)shop << 32) | movie;
    }
    
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        this->n = n;
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encode(shop, movie)] = price;
            unrented[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        auto &s = unrented[movie];
        int cnt = 0;
        for (auto it = s.begin(); it != s.end() && cnt < 5; ++it, ++cnt) {
            res.push_back(it->second); // shop id
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        rented.erase({price, shop, movie});
        unrented[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto it = rented.begin(); it != rented.end() && cnt < 5; ++it, ++cnt) {
            auto [price, shop, movie] = *it;
            res.push_back({shop, movie});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */