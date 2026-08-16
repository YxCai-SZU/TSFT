#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> n % 2 != 0;
    ensures \result == 0 ==> n % 2 == 0;
*/
int func(int n) {
    unsigned int n_unsigned;
    int ans;

    //@ assert 1 <= n <= 100;
    
    if (n < 0) {
        n_unsigned = (unsigned int)(-n);
    } else {
        n_unsigned = (unsigned int)n;
    }
    
    //@ assert 0 <= n_unsigned <= 100;
    
    if (n_unsigned % 2 != 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert ans == 1 || ans == 0;
    //@ assert ans == 1 ==> n % 2 != 0;
    //@ assert ans == 0 ==> n % 2 == 0;
    
    return ans;
}
