#include <stdbool.h>

/*@
    requires ((a) >= 0) && ((b) >= 0) && ((c) >= 0) && 
             ((d) >= 0) && ((e) >= 0) && ((k) >= 0);
    requires ((a) < 124) && ((b) < 124) && ((c) < 124) && 
             ((d) < 124) && ((e) < 124) && ((k) < 124);
    requires ((a) <= (b) && (b) <= (c) && (c) <= (d) && (d) <= (e));
    ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int abs_diff;
    
    //@ assert a <= e;
    
    if (e >= a) {
        //@ assert e - a >= 0;
        abs_diff = e - a;
    } else {
        //@ assert a - e >= 0;
        abs_diff = a - e;
    }
    
    //@ assert abs_diff == (e >= a ? e - a : a - e);
    //@ assert abs_diff == ((e) >= (a) ? (e) - (a) : (a) - (e));
    
    return abs_diff <= k;
}
