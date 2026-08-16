#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (a * b) % 2 == 0;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int c;
    bool is_even;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;

    c = a * b;

    //@ assert c == ((a) * (b));

    if (c % 2 == 0) {
        is_even = true;
    } else {
        is_even = false;
    }

    //@ assert is_even == ((c % 2) == 0);
    return is_even;
}
