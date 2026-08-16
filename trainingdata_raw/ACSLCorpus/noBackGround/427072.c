#include <stdbool.h>

/*@
    requires ((a) >= 0) && ((b) >= 0) && ((a) + (b) <= 100);
    ensures ((b) >= 0);
*/
void func(int a, int b)
{
    //@ assert ((b) >= 0);
}
