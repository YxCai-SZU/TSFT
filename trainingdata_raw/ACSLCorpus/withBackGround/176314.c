#include <stdbool.h>

/*@ predicate is_valid_params(integer d, integer t, integer s) =
      1 <= d <= 10000 &&
      1 <= t <= 10000 &&
      1 <= s <= 10000;
*/

/*@ lemma multiplication_bounds:
      \forall integer s, t;
        1 <= s <= 10000 && 1 <= t <= 10000 ==>
        s * t <= 10000 * 10000;
*/

/*@
  requires is_valid_params(d, t, s);
  ensures \result == true <==> d <= t * s;
  assigns \nothing;
*/
bool func(long d, long t, long s)
{
    long dist;
    long time;
    long speed;
    bool ans;
    
    dist = d;
    time = t;
    speed = s;
    
    //@ assert 1 <= speed <= 10000;
    //@ assert 1 <= time <= 10000;
    //@ assert speed * time <= 10000 * 10000;
    
    if (speed * time >= dist) {
        ans = true;
    } else {
        ans = false;
    }
    
    //@ assert ans == true <==> d <= t * s;
    return ans;
}
