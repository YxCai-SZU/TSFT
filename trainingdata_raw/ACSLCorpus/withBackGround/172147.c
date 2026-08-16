#include <stdbool.h>

/*@
    predicate is_mod_zero(integer x) = x % 3 == 0;
    logic integer mod_three(integer x) = x - ((x / 3) * 3);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int a_u32;
    unsigned int b_u32;
    unsigned int a_mod_3;
    unsigned int b_mod_3;
    unsigned int sum_mod_3;
    bool result;

    a_u32 = a;
    b_u32 = b;

    a_mod_3 = a_u32 - ((a_u32 / 3) * 3);
    //@ assert a_mod_3 == mod_three(a_u32);

    b_mod_3 = b_u32 - ((b_u32 / 3) * 3);
    //@ assert b_mod_3 == mod_three(b_u32);

    sum_mod_3 = (a_u32 + b_u32) - (((a_u32 + b_u32) / 3) * 3);
    //@ assert sum_mod_3 == mod_three(a_u32 + b_u32);

    result = (a_mod_3 == 0) || (b_mod_3 == 0) || (sum_mod_3 == 0);
    //@ assert result == (mod_three(a_u32) == 0 || mod_three(b_u32) == 0 || mod_three(a_u32 + b_u32) == 0);

    return result;
}
