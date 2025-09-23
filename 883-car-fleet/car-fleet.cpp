class Solution {
public:
    class Car {
    public:
        int p, s;
        Car(int posi, int speed) {
            p = posi;
            s = speed;
        }
    };

    static bool myComp(Car &a, Car &b) {
        return a.p > b.p;  // sort by position descending
    }

    int fleetCar(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> car;

        for (int i = 0; i < position.size(); i++) {
            Car cr(position[i], speed[i]);
            car.push_back(cr);
        }

        sort(car.begin(), car.end(), myComp);

        stack<float> st;
        for (auto i : car) {
            float time = ((float)target - i.p) / ((float)i.s);

            // Corrected condition: only pop fleets that are slower
            if (st.empty() || time > st.top()) {
                st.push(time);  // new fleet
            }
            // else → car merges with fleet ahead, do nothing
        }
        return st.size();
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        return fleetCar(target, position, speed);
    }
};
