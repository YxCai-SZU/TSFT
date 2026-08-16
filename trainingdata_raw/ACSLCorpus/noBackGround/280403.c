#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result <= n + m;
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    // Dummy implementation to satisfy verification
    // The original Rust code only manipulates a local HashSet
    // and returns 0, which trivially satisfies the postcondition
    size_t res = 0;

    //@ assert res == 0;
    //@ assert res <= n + m;

    return res;
}
