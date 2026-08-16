#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a == ((b) + (c)) || b == ((a) + (c)) || c == ((a) + (b)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool a_is_b_plus_c = false;
    bool b_is_a_plus_c = false;
    bool c_is_a_plus_b = false;

    //@ assert (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert ((b) + (c)) <= 200;
    if (a == b + c) {
        a_is_b_plus_c = true;
    }

    //@ assert (1 <= (a) <= 100) && (1 <= (c) <= 100);
    //@ assert ((a) + (c)) <= 200;
    if (b == a + c) {
        b_is_a_plus_c = true;
    }

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    //@ assert ((a) + (b)) <= 200;
    if (c == a + b) {
        c_is_a_plus_b = true;
    }

    //@ assert a_is_b_plus_c == (a == ((b) + (c)));
    //@ assert b_is_a_plus_c == (b == ((a) + (c)));
    //@ assert c_is_a_plus_b == (c == ((a) + (b)));

    return a_is_b_plus_c || b_is_a_plus_c || c_is_a_plus_b;
}
