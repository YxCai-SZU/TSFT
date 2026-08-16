#include <limits.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((l / 3) * (l / 3) * (l / 3));
    assigns \nothing;
*/
int func(int l)
{
    int l_div_3;
    int temp_l;
    int count;
    
    l_div_3 = 0;
    temp_l = l;
    count = 0;
    
    /*@
        loop invariant (1 <= (l) <= 1000);
        loop invariant (0 <= (temp_l) <= (l));
        loop invariant ((temp_l) == (l) - 3 * (count));
        loop invariant (0 <= (count) <= (l) / 3);
        loop invariant ((count) == ((l) - (temp_l)) / 3);
        loop assigns temp_l, count;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        count += 1;
    }
    
    l_div_3 = count;
    
    //@ assert l_div_3 >= 0 && l_div_3 <= 333;
    //@ assert l_div_3 * l_div_3 <= 333 * 333;
    //@ assert l_div_3 * l_div_3 * l_div_3 <= 333 * 333 * 333;
    
    return l_div_3 * l_div_3 * l_div_3;
}
