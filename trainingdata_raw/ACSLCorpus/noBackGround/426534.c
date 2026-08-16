#include <limits.h>

/*@ requires ((a) >= 0 && (a) <= 123 &&
    (b) >= 0 && (b) <= 123 &&
    (c) >= 0 && (c) <= 123 &&
    (d) >= 0 && (d) <= 123 &&
    (e) >= 0 && (e) <= 123 &&
    (k) >= 0 && (k) <= 123 &&
    (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e, int k) {
    //@ assert e >= a;
    //@ assert e - a >= 0;
    //@ assert e - a <= INT_MAX;
    //@ assert k <= INT_MAX;
    
    return e - a <= k;
}
