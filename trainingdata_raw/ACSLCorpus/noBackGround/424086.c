#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3);
    ensures \result == ((((a) * (b)) % 2) != 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    unsigned long long product;
    bool is_odd;
    unsigned long long temp;

    product = a * b;
    is_odd = false;
    temp = product;

    /*@
        loop invariant 1 <= a <= 3;
        loop invariant 1 <= b <= 3;
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    //@ assert temp == product % 2;
    //@ assert product % 2 == (a * b) % 2;

    if (temp == 1)
    {
        is_odd = true;
    }

    //@ assert is_odd == ((a * b) % 2 != 0);

    return is_odd;
}
