class Solution {
public:
    static bool compareMeetings(vector<int>& meetings1, vector<int>& meetings2){
        return meetings1[0] < meetings2[0];
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compareMeetings);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> endTimeWithRoom;
        priority_queue<int, vector<int>, greater<int>> meetingRoomsAvailable;
        vector<int> roomTracker(n, 0);

        for(int i = 0; i < n; i++) meetingRoomsAvailable.push(i);

        for(auto i : meetings){
            int start = i[0], end = i[1];

            while(endTimeWithRoom.size() > 0 && endTimeWithRoom.top().first <= start){
                pair<int, int> room = endTimeWithRoom.top();
                endTimeWithRoom.pop();
                meetingRoomsAvailable.push(room.second);
            }

            if(meetingRoomsAvailable.size() > 0){
                int room = meetingRoomsAvailable.top();
                meetingRoomsAvailable.pop();
                roomTracker[room]++;
                endTimeWithRoom.push({end, room});
            } else {
                pair<long long, int> room = endTimeWithRoom.top();
                endTimeWithRoom.pop();
                roomTracker[room.second]++;
                endTimeWithRoom.push({room.first + (end - start), room.second});
            }
        }

        int max = *max_element(roomTracker.begin(), roomTracker.end());
        for(int i = 0; roomTracker.size(); i++){
            if(max == roomTracker[i]) return i;
        }

        return 0;
    }
};
