#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000 &&
        1 <= (b) && (b) <= 10000);
    ensures \result == (((a) * (b)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_even;
    unsigned int temp;

    // Precondition check (implicit from requires)
    //@ assert (1 <= (a) && (a) <= 10000 &&         1 <= (b) && (b) <= 10000);

    // Ensure multiplication does not overflow
    //@ assert ((a) * (b)) <= 100000000;

    product = a * b;
    is_even = false;
    temp = product;

    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp <= ((a) * (b));
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 0)
    {
        is_even = true;
    }

    // Postcondition verification
    //@ assert is_even == (((a) * (b)) % 2 == 0);

    return is_even;
}
