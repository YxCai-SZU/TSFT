#include <stdint.h>

/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result >= 0;
    ensures \result <= (((A) + (P)) * 3);
    ensures \result == (((((A)) + ((P))) * 3) - (((A)) * 3 + ((P)))) || \result == 0;
    assigns \nothing;
*/
int32_t func(int32_t A, int32_t P)
{
    // Variable declarations at top of scope
    int32_t result;

    // Precondition verification
    //@ assert 0 <= A && A <= 100;
    //@ assert 0 <= P && P <= 100;

    // Arithmetic bounds verification
    //@ assert A * 3 <= 300;
    //@ assert A * 3 + P <= 400;
    //@ assert (A + P) * 3 <= 600;
    //@ assert (A + P) * 3 - (A * 3 + P) >= 0;

    result = A * 3 + P;

    if (result > 0)
    {
        result = result - (A * 3 + P);
        //@ assert result == 0;

        if (result > 0)
        {
            result = result * -1;
        }
    }

    // Postcondition verification
    //@ assert result >= 0;
    //@ assert result <= (((A) + (P)) * 3);
    //@ assert result == (((((A)) + ((P))) * 3) - (((A)) * 3 + ((P)))) || result == 0;

    return result;
}

