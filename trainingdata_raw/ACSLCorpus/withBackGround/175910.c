#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_even_divisible_by_3_or_5(size_t *input, integer n) =
      \forall integer i; 0 <= i < n ==> 
        (input[i] % 2 == 0 ==> (input[i] % 3 == 0 || input[i] % 5 == 0));
 */

/*@
  requires 1 <= n;
  requires \valid_read(input + (0 .. n-1));
  assigns \nothing;
  ensures \result == true <==> all_even_divisible_by_3_or_5(input, n);
*/
bool func(size_t n, const size_t *input) {
    bool ans = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans == true <==> 
        \forall integer j; 0 <= j < i ==> 
          (input[j] % 2 == 0 ==> (input[j] % 3 == 0 || input[j] % 5 == 0));
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        size_t value = input[i];
        if (value % 2 == 0) {
            if (value % 3 != 0 && value % 5 != 0) {
                ans = false;
            }
        }
        i += 1;
    }
    return ans;
}
