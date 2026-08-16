#include <stdbool.h>

/*@
    requires \forall integer i; ((i) % 2 == 0) ==> (\true);
    requires ((x) % 2 == 0);
    ensures (\true);
*/
void forall_isolation(int x)
{
    //@ assert (\true);
}
