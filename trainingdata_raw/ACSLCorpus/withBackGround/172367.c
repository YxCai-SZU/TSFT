#include <stdbool.h>

/*@
    predicate is_divisible(integer n, integer k) =
        n % k == 0;
*/

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= k && k <= 100;
    ensures \result >= 0 && \result <= 1;
    ensures \result == 1 ==> is_divisible(n, k);
    ensures \result == 0 ==> !is_divisible(n, k);
*/
int func(int n, int k) {
    int res;
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= k && k <= 100;
    
    if (n % k == 0) {
        //@ assert is_divisible(n, k);
        res = 1;
    } else {
        //@ assert !is_divisible(n, k);
        res = 0;
    }
    
    //@ assert res >= 0 && res <= 1;
    return res;
}
