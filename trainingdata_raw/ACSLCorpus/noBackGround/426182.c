#include <stdbool.h>

/*@
    requires (1 <= (a) <= 5);
    ensures (1 <= (a) <= 5);
*/
void func(int a)
{
    //@ assert (1 <= (a) <= 5);
}
