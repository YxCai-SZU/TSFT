#include <stdbool.h>
/*@
    requires 1 <= n <= 100;
    ensures ((n) % 2 == 0) ==> \result == 1;
    ensures ((n) % 2 != 0) ==> \result == n;
*/
int func(int n) {
    int result;
    //@ assert 1 <= n <= 100;
    if (n % 2 == 0) {
        result = 1;
        //@ assert ((n) % 2 == 0);
        //@ assert result == 1;
    } else {
        //@ assert ((n) % 2 != 0);
        result = n;
        //@ assert result == n;
    }
    return result;
}
