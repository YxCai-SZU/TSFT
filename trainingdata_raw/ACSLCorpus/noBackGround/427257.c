#include <stdbool.h>
#include <stdint.h>

/*@ requires (1 <= (n) && (n) <= 1000000000000000000);
    ensures \result <= n;
    assigns \nothing;
 */
uint64_t func(uint64_t n)
{
    uint64_t count = 0;
    uint64_t i = 1;
    
    //@ assert ((1 <= ((n)) && ((n)) <= 1000000000000000000) &&       1 <= (i) && (i) <= (n) / 3 + 1 &&       (count) <= (i) - 1);
    
    /*@ loop invariant ((1 <= ((n)) && ((n)) <= 1000000000000000000) &&
      1 <= (i) && (i) <= (n) / 3 + 1 &&
      (count) <= (i) - 1);
      @ loop assigns count, i;
      @ loop variant n / 3 - i + 1;
      @*/
    while (i <= n / 3) {
        bool is_divisible_by_3 = true;
        uint64_t j = 0;
        uint64_t num = i;
        
        //@ assert ((1 <= ((n)) && ((n)) <= 1000000000000000000) &&       0 <= (j) && (j) <= 3 &&       (num) >= 0);
        
        /*@ loop invariant ((1 <= ((n)) && ((n)) <= 1000000000000000000) &&
      0 <= (j) && (j) <= 3 &&
      (num) >= 0);
          @ loop assigns is_divisible_by_3, num, j;
          @ loop variant 3 - j;
          @*/
        while (j < 3) {
            if (num % 10 == 0) {
                is_divisible_by_3 = false;
                break;
            }
            num /= 10;
            j += 1;
        }
        
        if (is_divisible_by_3) {
            count += 1;
        }
        
        i += 1;
    }
    
    //@ assert count <= n;
    return count;
}
