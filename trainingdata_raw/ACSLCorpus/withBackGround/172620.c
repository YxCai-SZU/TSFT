#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int* a, integer n) =
      n > 0 && n <= 200000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;
*/

/*@ lemma loop_invariant_maintained:
      \forall integer n, i, res;
      n > 0 && n <= 200000 &&
      0 <= i <= n-1 &&
      res >= 1 && res <= i+1 ==>
      (i < n-1 ==> 0 <= i+1 <= n-1) &&
      (i < n-1 ==> (res >= 1 && res <= (i+1)+1));
*/

/*@
  requires is_valid_array(a, n);
  assigns \nothing;
  ensures \result >= 0;
*/
int func(size_t n, int* a) {
    int res = 1;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n-1;
      loop invariant res >= 1;
      loop invariant res <= i + 1;
      loop invariant is_valid_array(a, n);
      loop assigns i, res;
      loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i < n-1;
        
        if (a[i] >= a[i + 1]) {
            //@ assert a[i] >= a[i+1];
            res += 1;
        } else {
            //@ assert a[i] < a[i+1];
            res = 1;
        }
        
        i += 1;
        
        //@ assert res >= 1;
    }
    
    //@ assert i == n-1;
    //@ assert res >= 0;
    return res;
}
