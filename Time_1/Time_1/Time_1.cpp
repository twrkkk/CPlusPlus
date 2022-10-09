//the first laboratory work task 10
/*
class Time <23:59:59>
initialize by string, numbers, seconds, time 
   *calculate difference between two times in seconds
   *sum of time and seconds
   *subtracting seconds from time 
   * compare two times 
   * translation to minutes(rounding to a whole), seconds

*/
#include <iostream>
#include "Time.h"
using std::cin;
using std::cout;
int main()
{
    cout << "Enter first time" << '\n';
    int h, m, s;
    cin >> h >> m >> s;
    Time time(h, m, s);

    cout << "Enter second time" << '\n';
    cin >> h >> m >> s;
    Time time2(h, m, s);

    cout << time.toString() << '\n';
    cout<< time2.toString() << '\n';

    cout << "Difference between two times: " << time.calculateDifference(time2) << '\n';

    cout << "How many seconds will you add?" << '\n';
    int sec;
    cin >> sec;
    cout << "First time between changes: " << time.toString() << '\n';
    time.addSeconds(sec);
    cout << "First time after changes: " << time.toString() << '\n';

    cout << "Second time between changes: " << time2.toString() << '\n';
    time2.addSeconds(sec);
    cout << "Second time after changes: " << time2.toString() << '\n';

    cout << "compare time: " << time.compareTime(time2) << '\n';
}

