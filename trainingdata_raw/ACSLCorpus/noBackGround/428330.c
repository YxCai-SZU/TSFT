#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == (((((b) * 10 + (c))) % 4) < 1 || ((((a) * 10 + (b))) % 4) < 1 || ((((c) * 10 + (a))) % 4) < 1);
*/
bool func(int a, int b, int c)
{
    unsigned int bc;
    unsigned int ab;
    unsigned int ca;
    unsigned int bc_mod_4;
    unsigned int ab_mod_4;
    unsigned int ca_mod_4;
    bool result;

    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    
    bc = (unsigned int)(b * 10 + c);
    ab = (unsigned int)(a * 10 + b);
    ca = (unsigned int)(c * 10 + a);
    
    bc_mod_4 = bc % 4;
    ab_mod_4 = ab % 4;
    ca_mod_4 = ca % 4;
    
    //@ assert bc_mod_4 == ((((b) * 10 + (c))) % 4);
    //@ assert ab_mod_4 == ((((a) * 10 + (b))) % 4);
    //@ assert ca_mod_4 == ((((c) * 10 + (a))) % 4);
    
    //@ assert (bc_mod_4 < 1 || ab_mod_4 < 1 || ca_mod_4 < 1) ==> (((((b) * 10 + (c))) % 4) < 1 || ((((a) * 10 + (b))) % 4) < 1 || ((((c) * 10 + (a))) % 4) < 1);
    
    if (bc_mod_4 < 1 || ab_mod_4 < 1 || ca_mod_4 < 1)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (bc_mod_4 < 1 || ab_mod_4 < 1 || ca_mod_4 < 1);
    return result;
}
