class MovieRentingSystem {
    unordered_map<int ,unordered_map<int,int>> price;
    unordered_map<int , set<pair<int,int>>> available;
    set<tuple<int,int,int>> rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e :entries) {
            int shop = e[0], movie = e[1], cost = e[2];
            price[shop][movie] = cost;
            available[movie].insert({cost ,shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int>res;
        if(available.find(movie) == available.end()) return res;
        int count = 0;
        for(auto &p : available[movie]){
            res.push_back(p.second);
            if(++count == 5 ) break;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int cost = price[shop][movie];
        available[movie].erase({cost,shop});
        rented.insert({cost,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int cost = price[shop][movie];
        rented.erase({cost,shop,movie});
         available[movie].insert({cost, shop});  
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto &t : rented) {
            auto [cost, shop, movie] = t;
            res.push_back({shop, movie});
            if (++count == 5) break;
        }
        return res; 
    }
};

