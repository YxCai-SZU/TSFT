#include <stddef.h>

/*@
    requires (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
    ensures \result == ((3 * (A) + (P)) / 2);
    ensures \result >= 0;
*/
size_t func(size_t A, size_t P)
{
    size_t K;
    size_t pies;

    K = 3 * A + P;
    pies = K / 2;

    //@ assert pies == ((3 * (A) + (P)) / 2);

    return pies;
}
