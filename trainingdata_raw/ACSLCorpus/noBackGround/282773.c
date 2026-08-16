#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((n) % (k) == 0);
    ensures \result == 1 ==> ((n) % (k) != 0);
*/
int func(int n, int k) {
    int n_mod_k;
    int res;

    n_mod_k = n % k;
    
    if (n_mod_k == 0) {
        //@ assert ((n) % (k) == 0);
        res = 0;
    } else {
        //@ assert ((n) % (k) != 0);
        res = 1;
    }
    
    return res;
}
