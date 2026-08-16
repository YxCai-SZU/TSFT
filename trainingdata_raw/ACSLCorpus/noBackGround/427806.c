#include <stdint.h>

/*@
  requires 1 <= a <= 10000 && 1 <= b <= 10000 && 1 <= k <= 10000;
  ensures 0 <= \result <= k;
  ensures \result == (\let diff = ((a) > (b) ? (a) - (b) : (b) - (a));
      diff < (k) ? (k) - diff : 0);
*/
int32_t max_circular_track_collisions(int32_t k, int32_t a, int32_t b)
{
    int32_t diff;
    int32_t result;

    //@ assert 1 <= a <= 10000 && 1 <= b <= 10000 && 1 <= k <= 10000;
    
    if (a > b) {
        //@ assert a > b;
        diff = a - b;
        //@ assert (((a) > (b) ==> (diff) == (a) - (b)) &&       ((a) <= (b) ==> (diff) == (b) - (a)));
    } else {
        //@ assert a <= b;
        diff = b - a;
        //@ assert (((a) > (b) ==> (diff) == (a) - (b)) &&       ((a) <= (b) ==> (diff) == (b) - (a)));
    }

    if (diff < k) {
        //@ assert diff < k;
        result = k - diff;
        //@ assert result == k - diff;
    } else {
        //@ assert diff >= k;
        result = 0;
        //@ assert result == 0;
    }

    //@ assert 0 <= result <= k;
    //@ assert result == (\let diff = ((a) > (b) ? (a) - (b) : (b) - (a));       diff < (k) ? (k) - diff : 0);
    return result;
}
