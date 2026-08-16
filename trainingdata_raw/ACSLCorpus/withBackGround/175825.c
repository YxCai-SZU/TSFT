#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_index(integer n, integer i) =
      0 <= i && i < n;
*/

/*@ predicate is_valid_value(integer v) =
      1 <= v && v <= 1000000000;
*/

/*@ predicate is_valid_array(integer n, int *arr) =
      n >= 1 && n <= 1000000 &&
      \forall integer i; 0 <= i < n ==> is_valid_value(arr[i]);
*/

/*@ lemma array_property_preserved:
      \forall integer n, int *arr, integer idx;
      is_valid_array(n, arr) && 0 <= idx < n ==>
      is_valid_value(arr[idx]);
*/

/*@
  requires is_valid_array(n, numbers);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
uint32_t func(uint32_t n, int *numbers) {
    uint32_t count = 0;
    uint32_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant is_valid_array(n, numbers);
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < n) {
        int i = numbers[index];
        
        //@ assert is_valid_value(i);
        
        if ((i % 2 == 1) && (index % 2 == 0)) {
            count = count + 1;
        }
        
        index = index + 1;
    }
    
    return count;
}
