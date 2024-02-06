class FoodRatings {
private:
    //(cuisine) -> (rating) -> {food1, food2, food3, ......., foodn}
    unordered_map<string,map<int,set<string>>> cuisineMap;
    // (food) -> <rating,cuisine>
    unordered_map<string,pair<int,string>> foodToMap;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++) {
            cuisineMap[cuisines[i]][ratings[i]].insert(foods[i]);
            foodToMap[foods[i]]={ratings[i],cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating=foodToMap[food].first;
        string curFoodCuisine=foodToMap[food].second;
        foodToMap[food].first=newRating;
        cuisineMap[curFoodCuisine][oldRating].erase(food);
        if(cuisineMap[curFoodCuisine][oldRating].empty()) {
            cuisineMap[curFoodCuisine].erase(oldRating);
        }
        cuisineMap[curFoodCuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *(cuisineMap[cuisine].rbegin()->second.begin());
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
