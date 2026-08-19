// Last updated: 19/08/2026, 16:02:07
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
         vector<string> result;

        // check all possible times
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {

                // count LEDs ON
                int leds =
                    __builtin_popcount(hour) +
                    __builtin_popcount(minute);

                if (leds == turnedOn) {

                    // format minute with leading zero
                    string time = to_string(hour) + ":" +
                                  (minute < 10 ? "0" : "") +
                                  to_string(minute);

                    result.push_back(time);
                }
            }
        }
        return result;
    }
};