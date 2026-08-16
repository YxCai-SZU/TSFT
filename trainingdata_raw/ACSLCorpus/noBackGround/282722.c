#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= s * t);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    int distance;
    int time;
    int speed;
    int distance_covered;
    bool result;

    // Precondition verification
    //@ assert 1 <= d && d <= 10000;
    //@ assert 1 <= t && t <= 10000;
    //@ assert 1 <= s && s <= 10000;

    // Overflow safety proof
    //@ assert s * t <= 10000 * 10000;

    distance = d;
    time = t;
    speed = s;

    // Calculate distance_covered with overflow safety
    if (speed * time < distance) {
        distance_covered = speed * time;
    } else {
        distance_covered = distance;
    }

    // Main verification property
    //@ assert distance_covered == (speed * time < distance ? speed * time : distance);
    
    result = (distance <= distance_covered);
    
    // Postcondition verification
    //@ assert result == (d <= s * t);
    
    return result;
}
