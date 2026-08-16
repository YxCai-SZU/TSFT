#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_array(integer n, int64_t *a) =
      n >= 2 && n <= 100000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 100000;
*/

/*@ logic integer count_value(integer n, integer idx, int64_t *a) =
      (a[idx] == 1) ? 0 :
      (a[(idx + 1) % n] == 1) ? 0 :
      ((a[idx] < a[(idx + 1) % n]) && (a[idx] > a[(idx + 1) % n])) ? 1 : 0;
*/

/*@ lemma count_bounds:
      \forall integer n, integer idx, int64_t *a;
      is_valid_array(n, a) && 0 <= idx < n ==> 0 <= count_value(n, idx, a) <= 1;
*/

/*@ lemma index_mod_bound:
      \forall integer n, integer idx;
      n > 0 && 0 <= idx < n ==> 0 <= (idx + 1) % n < n;
*/

/*@
  requires is_valid_array(n, a);
  assigns \nothing;
  ensures \result == 0 || \result == -1;
*/
int64_t func(uint64_t n, int64_t *a) {
    int64_t count = 0;
    uint64_t index = 0;
    
    //@ ghost uint64_t old_n = n;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant n == old_n;
        loop invariant is_valid_array(n, a);
        loop invariant \forall integer i; 0 <= i < index ==> 
            count_value(n, i, a) == (a[i] == 1 ? 0 : 
                (a[(i + 1) % n] == 1 ? 0 : 
                ((a[i] < a[(i + 1) % n]) && (a[i] > a[(i + 1) % n])) ? 1 : 0));
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        
        if (a[index] == 1) {
            index += 1;
            continue;
        }
        
        uint64_t next_index = (index + 1) % n;
        //@ assert 0 <= next_index < n;
        
        if (a[next_index] == 1) {
            index += 1;
            continue;
        }
        
        //@ assert a[index] != 1 && a[next_index] != 1;
        
        if ((a[index] < a[next_index]) && (a[index] > a[next_index])) {
            //@ assert count_value(n, index, a) == 1;
            count += 1;
        } else {
            //@ assert count_value(n, index, a) == 0;
        }
        
        index += 1;
    }
    
    //@ assert index == n;
    //@ assert 0 <= count <= n;
    
    if (count <= (int64_t)n - 2) {
        //@ assert count >= 0;
        return 0;
    } else {
        //@ assert count == n || count == n - 1;
        return -1;
    }
}
