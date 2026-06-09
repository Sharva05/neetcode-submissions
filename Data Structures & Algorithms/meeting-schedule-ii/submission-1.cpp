/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        });
        int days = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start < intervals[i - 1].end) {
                days++;
            }
        }
        return days;
    }
};
