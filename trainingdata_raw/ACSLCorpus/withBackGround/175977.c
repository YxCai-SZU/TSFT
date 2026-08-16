#include <stdbool.h>

/*@
    predicate is_divisible(integer n, integer k) =
        n % k == 0;

    predicate is_not_divisible(integer n, integer k) =
        n % k != 0;
*/

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= k && k <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> is_divisible(n, k);
    ensures \result == 1 ==> is_not_divisible(n, k);
*/
int func(int n, int k) {
    int res;
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= k && k <= 100;
    
    if (n % k == 0) {
        //@ assert is_divisible(n, k);
        res = 0;
    } else {
        //@ assert is_not_divisible(n, k);
        res = 1;
    }
    
    //@ assert res == 0 || res == 1;
    return res;
}

int main() {
    int n = 10;
    int k = 2;
    int result = func(n, k);
    return 0;
}
