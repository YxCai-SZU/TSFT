#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures ((\result) >= 0);
    ensures ((\result) == (a) - 2 * (b) || (\result) == 0);
*/
int func(int a, int b)
{
    int result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    
    if (a - 2 * b > 0) {
        //@ assert a - 2 * b >= 0;
        result = a - 2 * b;
    } else {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    //@ assert ((result) >= 0);
    //@ assert ((result) == (a) - 2 * (b) || (result) == 0);
    
    return result;
}
