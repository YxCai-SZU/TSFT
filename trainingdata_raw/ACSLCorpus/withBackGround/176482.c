#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_params(integer n, integer len, integer x) =
        1 <= n && n <= 100 &&
        1 <= len && len <= 100 &&
        1 <= x && x <= 10000;

    predicate valid_array(int *l, integer len) =
        \forall integer i; 0 <= i < len ==> 1 <= l[i] && l[i] <= 100;

    logic integer max_sum(integer index) = index * 100;
*/

/*@
    requires valid_params(n, len, x);
    requires valid_array(l, len);
    requires \valid_read(l + (0 .. len-1));
    ensures \result >= 0;
    ensures \result <= n + 1;
    assigns \nothing;
*/
size_t func(size_t n, size_t x, int *l, size_t len) {
    size_t d = 0;
    size_t ans = 1;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= len && index <= n;
        loop invariant d <= max_sum(index);
        loop invariant 1 <= ans <= index + 1;
        loop invariant valid_array(l, len);
        loop invariant valid_params(n, len, x);
        loop assigns d, ans, index;
        loop variant n - index;
    */
    while (index < len && index < n) {
        //@ assert 0 <= index < len;
        d += (size_t)l[index];
        
        if (d <= x) {
            ans += 1;
        } else {
            break;
        }
        index += 1;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n + 1;
    return ans;
}
