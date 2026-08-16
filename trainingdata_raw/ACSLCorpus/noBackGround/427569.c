#include <stddef.h>

/*@
    requires (2 <= (k) <= (n) <= 100000);
    requires (\valid((arr) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (arr)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (arr)[i] != (arr)[j]);
    assigns \nothing;
    ensures \result <= n - 1;
*/
size_t func(size_t n, size_t k, int *arr) {
    size_t ans;
    
    //@ assert n > 0 && n <= 100000;
    //@ assert k > 1 && k <= 100000;
    //@ assert n - 1 >= 0;
    //@ assert (n - 1 + k - 2) >= 0;
    
    ans = (n - 1 + k - 2) / (k - 1);
    
    //@ assert ans == (((n) - 1 + (k) - 2) / ((k) - 1));
    //@ assert ans <= n - 1;
    
    return ans;
}
