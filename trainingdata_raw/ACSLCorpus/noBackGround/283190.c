#include <stdint.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures (-100000000 <= (\result) <= 100000000);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t max_val;
    int64_t ab_product;
    int64_t cd_product;
    
    //@ assert (-100000000 <= (a * b) <= 100000000);
    //@ assert (-100000000 <= (c * d) <= 100000000);
    
    ab_product = a * b;
    cd_product = c * d;
    
    if (ab_product > cd_product) {
        max_val = ab_product;
    } else {
        max_val = cd_product;
    }
    
    //@ assert max_val == ab_product || max_val == cd_product;
    return max_val;
}
