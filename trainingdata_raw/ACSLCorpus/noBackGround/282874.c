#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123);
    ensures \result == true <==> ((e) - (a)) <= k;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int dist;
    unsigned int max_dist;

    // Variable declarations at scope top
    dist = e - a;
    max_dist = a;

    // Manual max computation
    //@ assert max_dist == a;
    if (b > max_dist) {
        max_dist = b;
    }
    //@ assert max_dist >= a && max_dist >= b;
    if (c > max_dist) {
        max_dist = c;
    }
    //@ assert max_dist >= a && max_dist >= b && max_dist >= c;
    if (d > max_dist) {
        max_dist = d;
    }
    //@ assert max_dist >= a && max_dist >= b && max_dist >= c && max_dist >= d;
    if (e > max_dist) {
        max_dist = e;
    }
    //@ assert max_dist >= a && max_dist >= b && max_dist >= c && max_dist >= d && max_dist >= e;

    if (dist <= k) {
        //@ assert ((e) - (a)) <= k;
        return true;
    } else {
        //@ assert !(((e) - (a)) <= k);
        return false;
    }
}
