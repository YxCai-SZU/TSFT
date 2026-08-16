#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_range(size_t n) = 1 <= n <= 200000; */
/*@ predicate valid_array(size_t* arr, size_t n) = 
      \forall size_t i; 0 <= i < n ==> 1 <= arr[i] <= n; */
/*@ predicate loop_invariant(size_t i, size_t n, int ans, size_t current) = 
      0 <= i <= n && 0 <= ans <= (int)i && 0 <= current <= i; */

/*@
  requires valid_range(n);
  requires \valid_read(input_numbers + (0 .. n-1));
  requires valid_array(input_numbers, n);
  ensures 0 <= \result <= (int)n;
  assigns \nothing;
*/
int func(size_t n, const size_t* input_numbers) {
    int ans = 0;
    size_t current = 0;
    size_t i = 0;
    
    /*@
      loop invariant loop_invariant(i, n, ans, current);
      loop assigns ans, current, i;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (current == input_numbers[i]) {
            current += 1;
        } else {
            ans += 1;
            current = 1;
        }
        i += 1;
    }
    return ans;
}
