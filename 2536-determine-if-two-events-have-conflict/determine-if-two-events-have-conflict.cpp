class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
            int eve1St = stoi(event1[0].substr(0,2))* 60 + stoi(event1[0].substr(3,5));
            int eve1En = stoi(event1[1].substr(0,2))* 60 + stoi(event1[1].substr(3,5));
            int eve2St = stoi(event2[0].substr(0,2))* 60 + stoi(event2[0].substr(3,5));
            int eve2En = stoi(event2[1].substr(0,2))* 60 + stoi(event2[1].substr(3,5));

            vector<pair<int,int>>even;
            even.push_back({eve1St,eve1En});
            even.push_back({eve2St,eve2En});

            sort(even.begin(),even.end());


            auto i = even[0];

            auto j = even[1];

            if(j.first<=i.second) return true;
            return false;


    }
};