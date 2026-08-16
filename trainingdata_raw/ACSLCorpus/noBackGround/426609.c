#include <stdbool.h>

/*@
    requires ((n) >= 2 && (k) >= 2 && (k) <= (n) && (n) <= 100000 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (n) &&
    \forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
    ensures \result == (n - k >= a[k-1]);
    assigns \nothing;
*/
bool func(int n, int k, int *a) {
    int n_minus_k;
    int a_k_minus_1;
    
    //@ assert n >= 2 && k >= 2 && k <= n && n <= 100000;
    n_minus_k = n - k;
    
    //@ assert k-1 >= 0 && k-1 < n;
    a_k_minus_1 = a[k-1];
    
    if (n_minus_k < a_k_minus_1) {
        return false;
    } else {
        return true;
    }
}
