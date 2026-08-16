#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_even_in_range(unsigned long *numbers, integer i) =
      \forall integer j; 0 <= j < i ==> numbers[j] % 2 == 0;
*/

/*@
  requires n > 0 && n <= 100000;
  requires \valid_read(numbers+(0..n-1));
  requires \forall integer i; 0 <= i < n ==> numbers[i] > 0 && numbers[i] <= 1000000000;
  ensures \result == true <==> \forall integer i; 0 <= i < n ==> numbers[i] % 2 == 0;
  assigns \nothing;
*/
bool func(size_t n, const unsigned long *numbers) {
    bool all_even = true;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant all_even == true <==> all_even_in_range((unsigned long *)numbers, i);
      loop assigns i, all_even;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (numbers[i] % 2 != 0) {
            all_even = false;
        }
        i++;
    }
    return all_even;
}
