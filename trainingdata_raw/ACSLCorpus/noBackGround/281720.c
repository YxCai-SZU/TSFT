#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (d <= s * t);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    long long current_dist;
    long long speed;
    long long time;
    bool result;

    //@ assert (1 <= (d) <= 10000 &&         1 <= (t) <= 10000 &&         1 <= (s) <= 10000);
    
    //@ assert 1 <= s && s <= 10000;
    //@ assert 1 <= t && t <= 10000;
    //@ assert 1 <= ((s) * (t)) <= 10000 * 10000;
    
    current_dist = (long long)d;
    speed = (long long)s;
    time = (long long)t;
    
    //@ assert current_dist == (long long)d;
    //@ assert speed == (long long)s;
    //@ assert time == (long long)t;
    
    result = current_dist <= speed * time;
    
    //@ assert result == (d <= s * t);
    return result;
}
