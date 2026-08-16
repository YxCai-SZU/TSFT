#include <stddef.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
*/

/*@
    requires r_in_range(r);
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
size_t func(size_t r)
{
    // Variable declarations at top of scope
    size_t ans;

    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 300 * 100;
    //@ assert 3 * r * r >= 3 * 1 * 1;

    ans = 3 * r * r;
    return ans;
}

int main(void)
{
    return 0;
}
