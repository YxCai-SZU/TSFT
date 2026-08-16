#include <stdbool.h>
/*@
    predicate is_even(integer n) = n % 2 == 0;
    logic integer loop_bound(integer n) = (n % 2 == 0) ? n : 0;
    lemma result_non_negative:
        \forall integer n, result;
        1 <= n <= 100000 && result == loop_bound(n) ==> result >= 0;
*/

/*@
    requires 1 <= n <= 100000;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n) {
    int x;
    int result;
    int count;
    
    if (n % 2 == 1) {
        //@ assert n % 2 == 1;
        return 0;
    }
    
    x = 10;
    result = 0;
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant x >= 10;
        loop invariant count >= 0;
        loop invariant count <= 100000;
        loop invariant x <= 10 + 10 * count;
        loop invariant result >= 0;
        loop assigns x, result, count;
        loop variant 100000 - count;
    */
    while (x <= n && count < 100000) {
        if (x <= n) {
            result = n - x;
        } else {
            result = 0;
        }
        //@ assert result >= 0;
        x += 10;
        count += 1;
    }
    //@ assert result >= 0;
    return result;
}
