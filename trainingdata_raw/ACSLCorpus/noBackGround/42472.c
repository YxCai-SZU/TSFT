#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    ensures \result == (((a) * (b)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int result;
    bool is_even;
    unsigned int count;

    //@ assert ((a) * (b)) <= 10000 * 10000;
    result = a * b;
    is_even = false;
    count = result;

    /*@
        loop invariant 0 <= count <= ((a) * (b));
        loop invariant count % 2 == ((a) * (b)) % 2;
        loop invariant (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
        loop assigns count;
        loop variant count;
    */
    while (count >= 2)
    {
        count -= 2;
    }

    if (count == 0)
    {
        is_even = true;
    }

    //@ assert is_even == (((a) * (b)) % 2 == 0);
    return is_even;
}
