#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == ((a > b ? b : a) + c < d);
*/
bool func(int a, int b, int c, int d)
{
    int min_ab_val;
    int min_cd_val;
    bool result;
    
    // Calculate min(a,b)
    if (a > b) {
        min_ab_val = b;
    } else {
        min_ab_val = a;
    }
    
    // Calculate min(c,d)
    if (c > d) {
        min_cd_val = d;
    } else {
        min_cd_val = c;
    }
    
    //@ assert (((a) > (b) ==> (min_ab_val) == (b)) && ((a) <= (b) ==> (min_ab_val) == (a)));
    //@ assert (((c) > (d) ==> (min_cd_val) == (d)) && ((c) <= (d) ==> (min_cd_val) == (c)));
    
    result = (min_ab_val + c) < d;
    
    //@ assert min_ab_val == (a > b ? b : a);
    //@ assert min_cd_val == (c > d ? d : c);
    
    return result;
}
