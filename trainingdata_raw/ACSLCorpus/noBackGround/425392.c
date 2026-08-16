#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 10);
    ensures \result == ((x) + ((x) * (x)) + ((x) * (x) * (x)));
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    //@ assert (1 <= (x) && (x) <= 10);
    //@ assert ((x) + ((x) * (x)) + ((x) * (x) * (x))) <= 1331;
    return x + (x * x) + (x * x * x);
}

int main()
{
    return 0;
}
