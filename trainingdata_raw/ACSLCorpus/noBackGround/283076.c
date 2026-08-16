#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures (((a) % 2 == 0) ==> \result == 1) && (((a) % 2 != 0) ==> \result == 1);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    //@ assert a % 2 == 0 || a % 2 != 0;
    return 1;
}

int main()
{
    return 0;
}
