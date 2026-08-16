#include <stdbool.h>
#include <stdint.h>

/*@
  requires (2 <= (n) <= 200000);
  requires \valid_read(numbers + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
  ensures \result >= 0;
  ensures \result <= n;
*/
int64_t func(uint32_t n, int64_t* numbers) {
    int64_t count = 0;
    int64_t a = 0;
    int64_t b = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant (2 <= (n) <= 200000);
      loop invariant \valid_read(numbers + (0 .. n-1));
      loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
      loop invariant count >= 0;
      loop invariant count <= i;
      loop invariant (i > 0 ==> ((1 <= (a) <= 1000000000) || (a == 0 && i == 0)));
      loop invariant (i > 1 ==> ((1 <= (b) <= 1000000000) || (b == 0 && i == 0) || (b == 0 && i == 1)));
      loop assigns i, count, a, b;
    */
    while (i < n) {
        if (i == 0) {
            a = numbers[i];
        } else if (i == 1) {
            b = numbers[i];
        } else {
            int64_t x = numbers[i];
            if ((a < x && x < b) || (a > x && x > b)) {
                count += 1;
                if (a < x && x < b) {
                    a = x;
                } else {
                    b = x;
                }
            }
        }
        i += 1;
        //@ assert i <= n;
    }
    return count;
}
