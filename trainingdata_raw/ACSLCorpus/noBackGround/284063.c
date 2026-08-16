#include <stddef.h>

/*@
    requires (1 <= (A) && (A) <= 20 &&
        1 <= (B) && (B) <= 20 &&
        1 <= (T) && (T) <= 20);
    ensures \result == (((T) / (A)) * (B));
    assigns \nothing;
*/
size_t func(size_t A, size_t B, size_t T)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert A >= 1 && A <= 20;
    //@ assert B >= 1 && B <= 20;
    //@ assert T >= 1 && T <= 20;
    //@ assert T / A <= T;
    //@ assert (T / A) * B <= 400;

    result = (T / A) * B;
    return result;
}
