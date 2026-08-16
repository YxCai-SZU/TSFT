#include <stdbool.h>
#include <stddef.h>

/*@ predicate array_bounds(int *arr, integer len) =
      \valid(arr + (0 .. len-1));
*/

/*@ predicate valid_params(integer n, integer m, int *array, int *a) =
      n >= 0 && m >= 0 &&
      n <= 100000 && m <= 100000 &&
      array_bounds(array, n) &&
      array_bounds(a, m);
*/

/*@ lemma ans_bounds:
      \forall integer index, integer ans;
      0 <= index && 0 <= ans <= index ==> ans >= 0;
*/

/*@
  requires valid_params(n, m, array, a);
  ensures \result >= 0;
*/
int func(int n, int m, int *array, int *a) {
    int ans = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= m;
      loop invariant 0 <= ans <= index;
      loop invariant valid_params(n, m, array, a);
      loop assigns ans, index;
      loop variant m - index;
    */
    while (index < (size_t)m) {
        int i = a[index];
        bool found = false;
        size_t arr_index = 0;
        
        /*@
          loop invariant 0 <= arr_index <= n;
          loop invariant valid_params(n, m, array, a);
          loop assigns found, arr_index;
          loop variant n - arr_index;
        */
        while (arr_index < (size_t)n) {
            if (array[arr_index] == i) {
                found = true;
                break;
            }
            arr_index++;
        }
        
        if (found) {
            ans++;
        }
        index++;
    }
    
    //@ assert ans >= 0;
    return ans;
}
