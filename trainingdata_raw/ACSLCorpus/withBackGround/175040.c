#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer m, integer x) =
      1 <= n <= 100 &&
      1 <= m <= 100 &&
      1 <= x <= n - 1;
*/

/*@ predicate valid_array(integer m, size_t len, int* numbers, integer x) =
      len == m &&
      \forall integer i; 0 <= i < m ==> 1 <= numbers[i] <= 100 &&
      \forall integer i; 0 <= i < m ==> numbers[i] != x;
*/

/*@ predicate loop_invariant(integer i, integer m, integer l, integer r, int* numbers, integer x) =
      0 <= i <= m &&
      0 <= l <= i &&
      0 <= r <= i &&
      \forall integer j; 0 <= j < i ==> (numbers[j] > x ==> r > 0) &&
      \forall integer j; 0 <= j < i ==> (numbers[j] < x ==> l > 0);
*/

/*@ lemma bounds_preserved:
      \forall integer m, x, i, l, r, int* numbers;
      loop_invariant(i, m, l, r, numbers, x) &&
      i < m ==>
      0 <= l + (numbers[i] < x ? 1 : 0) <= i + 1 &&
      0 <= r + (numbers[i] > x ? 1 : 0) <= i + 1;
*/

/*@
  requires valid_params(n, m, x);
  requires valid_array(m, len, numbers, x);
  ensures \result <= m;
  assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m, unsigned int x, 
                  int* numbers, size_t len) {
    unsigned int l = 0;
    unsigned int r = 0;
    unsigned int i = 0;
    
    /*@
      loop invariant loop_invariant(i, m, l, r, numbers, x);
      loop assigns i, l, r;
      loop variant m - i;
    */
    while (i < m) {
        int tmp = numbers[i];
        
        //@ assert tmp != x;
        
        if (tmp > x) {
            r = r + 1;
            //@ assert r > 0;
        }
        
        if (tmp < x) {
            l = l + 1;
            //@ assert l > 0;
        }
        
        i = i + 1;
    }
    
    unsigned int min_val;
    if (r < l) {
        min_val = r;
    } else {
        min_val = l;
    }
    
    //@ assert min_val <= m;
    return min_val;
}
