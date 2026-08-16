#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures (1 <= (\result) <= 3 && (\result) != (a) && (\result) != (b) && (\result) + (a) + (b) == 6);
*/
int func(int a, int b)
{
    int result;

    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    result = 6 - a - b;
    
    //@ assert (1 <= (result) <= 3 && (result) != (a) && (result) != (b) && (result) + (a) + (b) == 6);
    
    return result;
}
