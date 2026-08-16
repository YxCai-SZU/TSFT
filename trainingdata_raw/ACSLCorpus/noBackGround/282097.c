#include <stdint.h>

/*@
  requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
  ensures \result >= 0;
  ensures \result <= a * b;
  assigns \nothing;
*/
int32_t func(int32_t a, int32_t b) {
    // Variable declarations at scope top
    int64_t product;
    int32_t result;
    int32_t i;
    int64_t sum;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    
    // Ensure no overflow in product calculation
    product = (int64_t)a * (int64_t)b;
    //@ assert (1 <= (product) && (product) <= 10000);
    
    result = 0;
    i = 0;
    sum = 0;
    
    /*@
      loop invariant 0 <= i;
      loop invariant i <= product / 2;
      loop invariant sum == 2 * i;
      loop invariant result == i;
      loop invariant product == (int64_t)a * (int64_t)b;
      loop invariant (1 <= (product) && (product) <= 10000);
      loop invariant result <= a * b;
      loop assigns i, sum, result;
      loop variant product - sum;
    */
    while (sum + 2 <= product) {
        //@ assert sum + 2 <= product;
        sum += 2;
        result += 1;
        i += 1;
        //@ assert sum == 2 * i;
        //@ assert result == i;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a * b;
    return result;
}
