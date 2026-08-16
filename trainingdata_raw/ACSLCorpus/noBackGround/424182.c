#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123);
    ensures \result == (k >= e - a || e - a < 0);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int dist;

    //@ assert (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123 &&         0 <= (k) && (k) <= 123);
    
    if (a > e) {
        dist = a - e;
    } else {
        dist = e - a;
    }

    //@ assert dist == ((a) > (e) ? (a) - (e) : (e) - (a));
    //@ assert dist >= 0;

    if (dist <= k) {
        //@ assert dist <= k;
        //@ assert k >= e - a || e - a < 0;
        return true;
    } else {
        //@ assert dist > k;
        //@ assert !(k >= e - a || e - a < 0);
        return false;
    }
}
