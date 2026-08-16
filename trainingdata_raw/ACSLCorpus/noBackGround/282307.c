#include <limits.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures ((\result) + (a) + (b) == 6) && (1 <= (\result) <= 3);
    assigns \nothing;
*/
int func(int a, int b)
{
    int c;
    //@ ghost int a_val = a;
    //@ ghost int b_val = b;
    
    c = 6 - a - b;
    
    //@ assert c == 6 - a_val - b_val;
    //@ assert (1 <= (a_val) <= 3) && (1 <= (b_val) <= 3) && ((a_val) != (b_val));
    //@ assert (1 <= (c) <= 3);
    
    //@ assert ((c) + (a_val) + (b_val) == 6);
    
    return c;
}
