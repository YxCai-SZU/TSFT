#include <stdint.h>

/*@ requires (1 <= (a) && (a) <= 10000 &&
      1 <= (b) && (b) <= 10000 &&
      1 <= (c) && (c) <= 10000 &&
      1 <= (d) && (d) <= 10000);
    ensures \result == a + d || \result == c + b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t min_value;
    int64_t sum_ad;
    int64_t sum_cb;
    
    sum_ad = a + d;
    sum_cb = c + b;
    
    //@ assert sum_ad == a + d;
    //@ assert sum_cb == c + b;
    
    if (sum_ad < sum_cb)
    {
        min_value = sum_ad;
        //@ assert min_value == a + d;
    }
    else
    {
        min_value = sum_cb;
        //@ assert min_value == c + b;
    }
    
    //@ assert min_value == a + d || min_value == c + b;
    
    return min_value;
}
