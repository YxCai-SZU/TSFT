#include <stdbool.h>

/*@
    requires 1 <= A <= 10000;
    requires 1 <= B <= 10000;
    ensures \result == ((A * B) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B)
{
    unsigned int C;
    bool is_even;

    //@ assert A * B <= 10000 * 10000;
    C = A * B;
    is_even = (C % 2 == 0);
    return is_even;
}
