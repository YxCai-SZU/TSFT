#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((n) % (k) == 0);
    ensures \result == 1 ==> ((n) % (k) != 0);
*/
int func(int n, int k) {
    int remainder;
    int result;

    remainder = n % k;
    
    if (remainder == 0) {
        //@ assert remainder == 0;
        result = 0;
    } else {
        //@ assert remainder != 0;
        result = 1;
    }
    
    return result;
}
