#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    ensures \result == 0 || \result == 1;
    ensures \result == (((n) % (k) != 0) ? 1 : 0);
*/
int func(unsigned int n, unsigned int k)
{
    int result;
    //@ assert (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    
    if (n % k != 0) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 0 || result == 1;
    //@ assert result == (((n) % (k) != 0) ? 1 : 0);
    
    return result;
}
