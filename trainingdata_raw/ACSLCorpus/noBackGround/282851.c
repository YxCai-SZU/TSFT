#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (n == 1 || n == 2 || n >= 4);
    ensures \result == 0 ==> (n == 3 || n == 1 || n == 2 || n >= 4);
*/
int func(long n)
{
    int result;
    
    //@ assert n == 1 || n == 2 || n == 3 || n >= 4;
    
    if (n == 1 || n == 2) {
        result = 1;
    } else if (n == 3) {
        result = 0;
    } else if (n >= 4) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 0 || result == 1;
    //@ assert result == 1 ==> (n == 1 || n == 2 || n >= 4);
    //@ assert result == 0 ==> (n == 3 || n == 1 || n == 2 || n >= 4);
    
    return result;
}
