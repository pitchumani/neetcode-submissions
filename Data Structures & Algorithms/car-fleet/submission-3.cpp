class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<std::pair<int, int>> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }
        // sort in reverse - the position
        std::sort(cars.rbegin(), cars.rend());
        double prevTime = (double)(target - cars[0].first) / cars[0].second;
        int fleets = 1;
        for (int i = 1; i < speed.size(); ++i) {
            double currTime = (double)(target - cars[i].first) / cars[i].second;
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};
