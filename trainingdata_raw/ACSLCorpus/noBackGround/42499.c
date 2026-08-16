#include <stdint.h>

/*@
  requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
  ensures \result == ((a) * (b) - ((a) + (b) - 1));
*/
int64_t func(uint64_t a, uint64_t b)
{
    // Variable declarations at top of scope
    uint64_t product;
    uint64_t sum_minus_one;
    uint64_t final_result;
    int64_t signed_result;
    
    //@ assert (1 <= (a) <= 20);
    //@ assert (1 <= (b) <= 20);
    
    product = a * b;
    //@ assert product == a * b;
    
    sum_minus_one = a + b - 1;
    //@ assert sum_minus_one == a + b - 1;
    
    //@ assert product >= sum_minus_one;
    
    final_result = product - sum_minus_one;
    //@ assert final_result == ((a) * (b) - ((a) + (b) - 1));
    
    signed_result = (int64_t)final_result;
    //@ assert signed_result == ((a) * (b) - ((a) + (b) - 1));
    
    return signed_result;
}
