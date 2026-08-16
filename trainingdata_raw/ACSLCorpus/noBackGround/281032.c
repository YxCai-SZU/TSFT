#include <stdint.h>

/*@
    requires (2 <= (N) && (N) <= 100 &&
        2 <= (M) && (M) <= 100);
    ensures \result == (((N) - 1) * ((M) - 1));
    assigns \nothing;
*/
int func(int N, int M)
{
    unsigned int N_unsigned;
    unsigned int M_unsigned;
    unsigned int result_unsigned;
    int result;

    N_unsigned = (unsigned int)N;
    M_unsigned = (unsigned int)M;

    //@ assert N_unsigned - 1 <= 99;
    //@ assert M_unsigned - 1 <= 99;
    //@ assert (N_unsigned - 1) * (M_unsigned - 1) <= 99 * 99;

    result_unsigned = (N_unsigned - 1) * (M_unsigned - 1);
    result = (int)result_unsigned;

    //@ assert result == (((N) - 1) * ((M) - 1));

    return result;
}
