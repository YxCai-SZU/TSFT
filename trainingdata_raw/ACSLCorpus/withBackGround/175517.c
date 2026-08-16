#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
*/
int func(int a, int b)
{
    int result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    
    if (a > 2 * b) {
        //@ assert a > 2 * b;
        result = a - 2 * b;
    } else {
        //@ assert a <= 2 * b;
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == a - 2 * b || result == 0;
    return result;
}
