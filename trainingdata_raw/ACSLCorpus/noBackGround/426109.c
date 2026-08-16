#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == 1 <==> ((((a)) % 3) == 0 || (((b)) % 3) == 0 || (((a) + (b)) % 3) == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    unsigned int a_unsigned;
    unsigned int b_unsigned;
    unsigned int sum_unsigned;
    unsigned int a_mod_3;
    unsigned int b_mod_3;
    unsigned int sum_mod_3;
    bool result;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (a < 0) {
        a_unsigned = (unsigned int)(a + 3);
    } else {
        a_unsigned = (unsigned int)a;
    }
    
    if (b < 0) {
        b_unsigned = (unsigned int)(b + 3);
    } else {
        b_unsigned = (unsigned int)b;
    }
    
    if (a + b < 0) {
        sum_unsigned = (unsigned int)(a + b + 3);
    } else {
        sum_unsigned = (unsigned int)(a + b);
    }
    
    a_mod_3 = a_unsigned % 3;
    b_mod_3 = b_unsigned % 3;
    sum_mod_3 = sum_unsigned % 3;
    
    if (a_mod_3 == 0 || b_mod_3 == 0 || sum_mod_3 == 0) {
        //@ assert a_mod_3 == 0 || b_mod_3 == 0 || sum_mod_3 == 0;
        result = true;
    } else {
        //@ assert a_mod_3 != 0 && b_mod_3 != 0 && sum_mod_3 != 0;
        result = false;
    }
    
    //@ assert result == 1 <==> ((((a)) % 3) == 0 || (((b)) % 3) == 0 || (((a) + (b)) % 3) == 0);
    return result;
}
