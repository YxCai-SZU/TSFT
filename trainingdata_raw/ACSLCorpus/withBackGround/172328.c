#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_range(integer n) = 2 <= n <= 200000; */
/*@ predicate valid_numbers(integer n, int32_t *numbers) =
      \forall integer i; 0 <= i < n ==> 1 <= numbers[i] <= 1000000; */

/*@
  requires valid_range(n);
  requires \valid(numbers + (0 .. n-1));
  requires valid_numbers(n, numbers);
  ensures \result == (n >= 2);
*/
bool func(uint32_t n, int32_t *numbers) {
    uint32_t counter = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant counter <= i;
      loop invariant i > 0 ==> counter <= i + 1;
      loop assigns i, counter;
      loop variant n - i;
    */
    while (i < n) {
        if (i == 0 || i == n - 1) {
            counter += 1;
        } else {
            int32_t left = numbers[i - 1];
            int32_t right = numbers[i + 1];
            int32_t center = numbers[i];
            if ((left < center && right < center) || (left > center && right > center)) {
                counter += 1;
            }
        }
        i += 1;
        //@ assert i > 0 ==> counter <= i + 1;
    }
    return n >= 2;
}
