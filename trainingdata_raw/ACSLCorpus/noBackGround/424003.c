#include <stdbool.h>

/*@ requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
    assigns \nothing;
 */
bool func(int d, int t, int s)
{
    int speed;
    int time;
    int distance;
    bool result;
    
    speed = s;
    time = t;
    distance = d;
    
    //@ assert speed > 0 && time > 0 && distance > 0;
    //@ assert speed <= 10000 && time <= 10000 && distance <= 10000;
    //@ assert speed * time <= 10000 * 10000;
    //@ assert speed * time >= 0 && speed * time <= 2147483647;
    
    result = (speed * time >= distance);
    return result;
}
