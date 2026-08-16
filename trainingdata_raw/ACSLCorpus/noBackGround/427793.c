#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0);
    ensures ((\result) == (a) - 2 * (b) || (\result) == 0);
*/
int func(int a, int b)
{
    int result;
    int return_value;

    result = a - 2 * b;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    
    if (result < 0) {
        return_value = 0;
    } else {
        return_value = result;
    }
    
    //@ assert ((return_value) >= 0);
    //@ assert ((return_value) == (a) - 2 * (b) || (return_value) == 0);
    
    return return_value;
}
