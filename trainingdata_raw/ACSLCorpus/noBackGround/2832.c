#include <stddef.h>

/*@
    requires (1 <= (A) <= 20) && (1 <= (B) <= 20) && (1 <= (T) <= 20);
    ensures \result == T / A * B;
    assigns \nothing;
*/
size_t func(size_t A, size_t B, size_t T)
{
    // Variable declarations at scope top
    size_t ans;

    //@ assert (1 <= (A) <= 20);
    //@ assert (1 <= (B) <= 20);
    //@ assert (1 <= (T) <= 20);
    //@ assert T / A * B <= (T / A) * 20;

    ans = T / A * B;
    return ans;
}
