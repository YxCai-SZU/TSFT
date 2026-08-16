#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == (l / 3) * (l / 3) * (l / 3);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t l_div_3 = 0;
    int64_t temp_l = l;
    int64_t count = 0;
    
    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant 0 <= temp_l <= l;
        loop invariant temp_l == l - 3 * count;
        loop invariant 0 <= count <= l / 3;
        loop invariant count == (l - temp_l) / 3;
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
    
    int64_t result = l_div_3 * l_div_3 * l_div_3;
    return result;
}

int main()
{
    return 0;
}
