#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Declare all variables at the top
    int32_t result;

    //@ assert (1 <= (r) <= 100);
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 300 * 100;
    //@ assert 3 * r * r >= 3 * 1 * 1;

    result = 3 * r * r;
    return result;
}

int main()
{
    return 0;
}
