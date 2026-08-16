#include <stdint.h>
#include <stddef.h>

/*@ predicate is_valid_array(int64_t* a, size_t n) =
      n > 0 && n <= 200000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000000000;
*/

/*@ logic integer ans_upper_bound(integer i) = 1000000000 * i; */

/*@ lemma ans_nonnegative:
      \forall integer i; 0 <= i ==> ans_upper_bound(i) >= 0;
*/

/*@ requires is_valid_array(a, n);
    assigns \nothing;
    ensures \result >= 0;
*/
int64_t func(size_t n, int64_t* a) {
    int64_t ans = 0;
    int64_t prev_height = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant prev_height >= 0;
        loop invariant prev_height <= 1000000000;
        loop invariant ans <= ans_upper_bound(i);
        loop assigns ans, prev_height, i;
        loop variant n - i;
    */
    while (i < n) {
        int64_t a_height = a[i];
        
        //@ assert a_height > 0 && a_height <= 1000000000;
        
        if (a_height - prev_height < 0) {
            //@ assert prev_height - a_height >= 0;
            ans += prev_height - a_height;
        } else {
            prev_height = a_height;
        }
        
        //@ assert ans >= 0;
        i++;
    }
    
    return ans;
}
