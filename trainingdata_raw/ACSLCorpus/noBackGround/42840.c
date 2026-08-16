#include <stdint.h>

/*@
    requires (2 <= (A) <= 100) && (2 <= (B) <= 100);
    ensures \result == (((A) - 1) * ((B) - 1));
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    // Declare all variables at the top
    int64_t result;

    //@ assert A - 1 >= 1;
    //@ assert A - 1 <= 99;
    //@ assert B - 1 >= 1;
    //@ assert B - 1 <= 99;
    //@ assert 1 <= (A - 1) * (B - 1) <= 9801;

    result = (A - 1) * (B - 1);
    return result;
}
