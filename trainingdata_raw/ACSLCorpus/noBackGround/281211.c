#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures \result == (6 - ((a) + (b)));
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert 6 - (a + b) == 6 - (a + b);
    result = 6 - (a + b);
    
    return result;
}
