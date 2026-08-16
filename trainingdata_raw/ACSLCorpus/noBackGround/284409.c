#include <stdbool.h>

/*@
    requires ((a) >= 1 && (b) >= 1 && (c) >= 1 &&
        (a) <= 5000 && (b) <= 5000 && (c) <= 5000);
    ensures \result == ((((a) + (b) > (c) && (a) + (c) > (b) && (b) + (c) > (a)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert ((a) >= 1 && (b) >= 1 && (c) >= 1 &&         (a) <= 5000 && (b) <= 5000 && (c) <= 5000);
    
    bool result;
    
    //@ ghost int a_val = a;
    //@ ghost int b_val = b;
    //@ ghost int c_val = c;
    
    //@ assert a_val + b_val > c_val || a_val + c_val > b_val || b_val + c_val > a_val;
    
    result = (a + b > c) && (a + c > b) && (b + c > a);
    
    //@ assert result == ((((a_val) + (b_val) > (c_val) && (a_val) + (c_val) > (b_val) && (b_val) + (c_val) > (a_val)) ? 1 : 0) == 1);
    
    return result;
}
