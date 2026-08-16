#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(size_t n, int64_t *a) =
        n >= 2 && n <= 100000 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> (a[j] == j+1 || a[j] == j+2);
*/

/*@
    logic integer absolute_difference(integer x, integer y) =
        x < y ? y - x : x - y;
*/

/*@
    lemma diff_property:
        \forall integer x, y; (x == y+1 || x == y+2) ==> 
        (absolute_difference(x, y) == 1 || absolute_difference(x, y) == 2);
*/

/*@
    requires valid_array(n, a);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int32_t func(size_t n, const int64_t *a) {
    int32_t cnt = 0;
    size_t i = 1;
    
    //@ ghost int64_t *old_a = a;
    
    /*@
        loop invariant 1 <= i <= n;
        loop invariant cnt >= 0;
        loop invariant cnt <= (int32_t)i;
        loop invariant valid_array(n, old_a);
        loop invariant \forall integer j; 0 <= j < n ==> (old_a[j] == j+1 || old_a[j] == j+2);
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n) {
        int64_t diff;
        
        if (a[i] < a[i-1]) {
            diff = a[i-1] - a[i];
        } else {
            diff = a[i] - a[i-1];
        }
        
        //@ assert diff == absolute_difference(a[i], a[i-1]);
        
        if (diff == 1) {
            cnt += 1;
        }
        
        i += 1;
    }
    
    return cnt;
}
