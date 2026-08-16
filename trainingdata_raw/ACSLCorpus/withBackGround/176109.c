#include <stdint.h>
#include <stdbool.h>

/*@ predicate valid_array(int64_t *a, integer n) =
      n >= 2 && n <= 100000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> -1000000000 <= a[i] <= 1000000000;
*/

/*@ predicate count_bounds(integer cnt, integer i, integer n) =
      cnt >= 0 && cnt <= i-1 && cnt <= n-2;
*/

/*@ lemma count_always_nonnegative:
      \forall integer cnt, i, n; count_bounds(cnt, i, n) ==> cnt >= 0;
*/

/*@ lemma count_upper_bound:
      \forall integer cnt, i, n; count_bounds(cnt, i, n) ==> cnt <= n-2;
*/

/*@ requires valid_array(a, n);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n-2;
*/
int32_t func(uint32_t n, int64_t *a) {
    // Variable declarations at top of scope
    int32_t count = 0;
    uint32_t i = 1;
    
    /*@ loop invariant 1 <= i <= n-1;
        loop invariant count_bounds(count, i, n);
        loop assigns count, i;
        loop variant n-i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i-1 < n && 0 <= i < n && 0 <= i+1 < n;
        
        bool condition = (a[i-1] < a[i] && a[i] < a[i+1]) || 
                         (a[i-1] > a[i] && a[i] > a[i+1]);
        
        if (condition) {
            //@ assert count >= 0 && count <= i-1;
            int32_t old_count = count;
            count += 1;
            //@ assert count == old_count + 1;
        }
        
        i += 1;
        //@ assert count_bounds(count, i, n);
    }
    
    //@ assert count >= 0;
    //@ assert count <= n-2;
    
    return count;
}
