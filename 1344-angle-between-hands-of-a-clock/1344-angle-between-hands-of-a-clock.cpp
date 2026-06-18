class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;
        double difference = abs(hourAngle - minuteAngle);
        double result = min(difference, 360 - difference);

        return result;
    }
};