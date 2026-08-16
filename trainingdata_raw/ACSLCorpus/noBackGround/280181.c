#include <stdbool.h>
#include <stdint.h>

/*@
  requires 1 <= n <= 100000;
  ensures \result >= 0;
  ensures \result <= n / 2;
  assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t count = 0;
    uint32_t i = 1;
    
    /*@
      loop invariant 1 <= i <= (n / 2) + 1;
      loop invariant count >= 0;
      loop invariant count <= (int32_t)(i - 1);
      loop assigns i, count;
      loop variant (n / 2) - i + 1;
    */
    while (i <= (n / 2)) {
        uint32_t s = i * 2;
        bool is_even_divisor = false;
        
        /*@
          loop invariant 0 <= s <= i * 2;
          loop invariant s % 2 == (i * 2) % 2;
          loop invariant is_even_divisor == false;
          loop assigns s, is_even_divisor;
          loop variant s;
        */
        while (s > 0) {
            if (s == 1) {
                is_even_divisor = true;
                break;
            }
            s -= 2;
        }
        
        //@ assert is_even_divisor ==> ((i) % 2 == 0);
        
        if (is_even_divisor) {
            count += 1;
        }
        
        i += 1;
    }
    
    //@ assert count >= 0;
    
    return count;
}
