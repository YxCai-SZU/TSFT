#include <stdbool.h>

/*@
    requires (1 <= (A) <= 3 && 1 <= (B) <= 3);
    ensures \result == (((A) * (B)) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned long A, unsigned long B)
{
    unsigned long product;
    bool is_odd;

    //@ assert 1 <= A <= 3;
    product = A * B;
    is_odd = (product % 2) != 0;

    //@ assert product == A * B;
    return is_odd;
}
