#include <stdbool.h>
/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result <= c;
    ensures \result == b / a || \result == c;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int ans;
    unsigned int div_result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    div_result = b / a;

    //@ assert 0 <= div_result <= 100;
    //@ assert 1 <= c <= 100;

    if (div_result < c) {
        ans = div_result;
    } else {
        ans = c;
    }

    //@ assert ans <= c;
    //@ assert ans == b / a || ans == c;

    return ans;
}
