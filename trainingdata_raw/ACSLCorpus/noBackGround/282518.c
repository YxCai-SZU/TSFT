#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == ((a) == (b) ? (a) * 2 - 1 :
        ((a) == (b) - 1 || (b) == (a) - 1) ? (a) * 2 :
        (b) * 2 - 1);
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int result;
    //@ assert (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    
    if (a == b) {
        //@ assert a * 2 - 1 >= 0;
        result = a * 2 - 1;
    } else if (a == b - 1 || b == a - 1) {
        //@ assert a * 2 >= 0;
        result = a * 2;
    } else {
        //@ assert b * 2 - 1 >= 0;
        result = b * 2 - 1;
    }
    
    //@ assert result == ((a) == (b) ? (a) * 2 - 1 :         ((a) == (b) - 1 || (b) == (a) - 1) ? (a) * 2 :         (b) * 2 - 1);
    //@ assert result >= 0;
    return result;
}
