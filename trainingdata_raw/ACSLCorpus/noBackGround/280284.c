#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((((b) * 10 + (c)) % 4) < 1 || ((a) % 2) == 0);
    assigns \nothing;
*/
bool func(long a, long b, long c) {
    unsigned long b_unsigned;
    unsigned long c_unsigned;
    unsigned long a_unsigned;
    unsigned long bc_mod_4;
    bool bc_mod_4_0;
    unsigned long a_mod_2;
    bool result;

    b_unsigned = (unsigned long)b;
    c_unsigned = (unsigned long)c;
    a_unsigned = (unsigned long)a;

    //@ assert b_unsigned * 10 <= 90;
    //@ assert b_unsigned * 10 + c_unsigned <= 99;
    //@ assert (b_unsigned * 10 + c_unsigned) % 4 <= 3;

    bc_mod_4 = (b_unsigned * 10 + c_unsigned) % 4;
    bc_mod_4_0 = bc_mod_4 < 1;
    a_mod_2 = a_unsigned % 2;
    result = bc_mod_4_0 || (a_mod_2 == 0);

    return result;
}
