#include <stdint.h>

/*@
    requires (1 <= (x) <= 1);
    ensures \result == 0;
*/
int32_t func(uint32_t x)
{
    int32_t result;
    //@ assert 0 == 0;
    result = 0;
    return result;
}

int main()
{
    return 0;
}
