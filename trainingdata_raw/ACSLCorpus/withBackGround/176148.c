#include <stdbool.h>

/*@
    predicate valid_time(integer h, integer m) =
        h >= 0 && h < 24 && m >= 0 && m < 60;

    logic integer total_minutes(integer h, integer m) = h * 60 + m;

    predicate non_negative_difference(integer h1, integer m1, integer h2, integer m2, integer k) =
        total_minutes(h2, m2) - total_minutes(h1, m1) - k >= 0;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires k >= 0;
    requires non_negative_difference(h1, m1, h2, m2, k);
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int wake;
    int res;

    //@ assert total_minutes(h1, m1) == h1 * 60 + m1;
    //@ assert total_minutes(h2, m2) == h2 * 60 + m2;
    
    wake = h2 * 60 + m2 - (h1 * 60 + m1);
    
    //@ assert wake == total_minutes(h2, m2) - total_minutes(h1, m1);
    
    res = wake - k;
    
    //@ assert res == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    
    return res;
}
