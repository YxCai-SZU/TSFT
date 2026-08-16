#include <stdbool.h>

/*@
    requires (1 <= (X) && (X) <= 9);
    ensures \result == true ==> (X == 7 || X == 5 || X == 3);
    ensures \result == false ==> (X != 7 && X != 5 && X != 3);
    assigns \nothing;
*/
bool func(int X)
{
    //@ assert (1 <= (X) && (X) <= 9);
    return (X == 7 || X == 5 || X == 3);
}
