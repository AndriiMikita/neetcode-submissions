class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars = vector<pair<int, int>>(position.size());

        for(int i = 0; i < speed.size(); ++i)
            cars[i] = {position[i], speed[i]};

        sort(cars.begin(), cars.end(), greater<>());

        stack<pair<int, int>> st;

        for(auto& [pos, speed] : cars)
        {
            if(st.empty())
                st.push({pos, speed});

            auto& [lpos, lspeed] = st.top();

            cout << pos << " " << speed << " : " << (target - lpos) * speed << " " << (target - pos) * lspeed << '\n';

            if((target - lpos) * speed < (target - pos) * lspeed)
                st.push({pos, speed});
            
        }

        return st.size();
    }
};
