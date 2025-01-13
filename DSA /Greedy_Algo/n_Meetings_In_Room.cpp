// Description:
// You are given timings of n meetings in the form of (start[i], end[i])
// where start[i] is the start time of meeting i and end[i] is the finish time of meeting i.
// Return the maximum number of meetings that can be accommodated in a single meeting room,
// when only one meeting can be held in the meeting room at a particular time. 

// Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Examples :

// Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

// Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
// Output: 1
// Explanation: Only one meetings can be held with given start and end timings.

// Input: start[] = [1, 2], end[] = [100, 99]
// Output: 1

// Constraints:
// 1 ≤ n ≤ 105
// 0 ≤ start[i] < end[i] ≤ 106

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int meetingRoom(vector<int> start, vector<int> end){
    map<int, int> mp;
    int t_meetings = 0;
    map<int, int> mp_r;

    for (int i = 0; i < start.size(); i++)
    {
        if (i!=0 && end[i] == end[i-1])
        {
            mp[end[i]] = max(start[i], start[i-1]);
            continue;
        }
        
        mp[end[i]] = start[i];
        // cout << end[i] << " " << start[i] << endl;
    }
    int lastMeeting = -1;
    for (auto i : mp)
    {
        if (i.second>lastMeeting)
        {
            t_meetings++;
            lastMeeting = i.first;
        }
        // cout << "end: " << i.first <<  " start:" << i.second << endl;
        // cout << "last meeting: " << lastMeeting << endl;
    }
    return t_meetings;
}

int main() {


    vector<int> start;
    start.push_back(1);
    start.push_back(2);
    // start.push_back(20);
    // start.push_back(5);
    // start.push_back(8);
    // start.push_back(5);
    vector<int> end;
    end.push_back(100);
    end.push_back(99);
    // end.push_back(30);
    // end.push_back(7);
    // end.push_back(9);
    // end.push_back(9);

    // meetingRoom(start, end);


    cout << meetingRoom(start, end) << endl;

    return 0;
}