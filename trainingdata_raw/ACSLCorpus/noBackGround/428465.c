#include <stdint.h>

/*@
    requires (0 <= (X) <= 9) && (0 <= (A) <= 9);
    ensures ((X) < (A)) ==> \result == 0;
    ensures ((X) >= (A)) ==> \result == 10;
    assigns \nothing;
*/
int32_t func(int64_t X, int64_t A)
{
    int32_t result;

    //@ assert (0 <= (X) <= 9) && (0 <= (A) <= 9);

    if (X < A)
    {
        //@ assert ((X) < (A));
        result = 0;
    }
    else
    {
        //@ assert ((X) >= (A));
        result = 10;
    }

    return result;
}
