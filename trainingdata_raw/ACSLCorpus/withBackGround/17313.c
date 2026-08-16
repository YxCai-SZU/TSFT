#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_range(integer n) = 1 <= n && n <= 100; */
/*@ predicate valid_array(int32_t *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 1000; */
/*@ predicate unchanged(int32_t *arr, integer n, int32_t *old) = 
      \forall integer i; 0 <= i < n ==> arr[i] == old[i]; */

/*@
  requires valid_range(n);
  requires \valid_read(numbers + (0 .. n-1));
  requires valid_array(numbers, n);
  assigns \nothing;
  ensures \result <= n;
*/
uint32_t func(uint32_t n, int32_t *numbers) {
    uint32_t count = 0;
    uint32_t i = 0;
    int32_t *old_numbers = numbers;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant count <= i;
      loop invariant valid_range(n);
      loop invariant valid_array(numbers, n);
      loop invariant unchanged(numbers, n, old_numbers);
      loop invariant i <= n;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        int32_t a = numbers[i];
        //@ assert 1 <= a && a <= 1000;
        if (a % 2 == 1 && (i + 1) % 2 == 1) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
