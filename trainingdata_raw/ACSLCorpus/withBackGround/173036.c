#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_array(int32_t* arr, size_t n) =
      n > 0 && n <= 200000 &&
      \valid(arr + (0 .. n-1)) &&
      \forall size_t i; 0 <= i < n ==> -1000000000 <= arr[i] <= 1000000000;
*/

/*@ lemma result_bounds:
      \forall size_t n, index, result;
      n > 0 && n <= 200000 &&
      0 <= index <= n &&
      result >= 0 && result <= index ==>
      result <= n;
*/

/*@
  requires valid_array(a, n);
  ensures 0 <= \result <= n;
  assigns \nothing;
*/
int32_t func(size_t n, int32_t* a) {
    int32_t p = 0;
    int32_t result = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant result >= 0;
      loop invariant result <= index;
      loop invariant valid_array(a, n);
      loop assigns p, result, index;
      loop variant n - index;
    */
    while (index < n) {
        int32_t x = a[index];
        if (x == p) {
            result += 1;
        } else {
            p = x;
        }
        index += 1;
        
        //@ assert result <= index;
    }
    
    //@ assert result <= n;
    return result;
}
