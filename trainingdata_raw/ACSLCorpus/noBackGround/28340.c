#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures \result == -1 ||
        (\result >= 0 &&
         (((unsigned long long)\result * 8) / 100) == a &&
         (((unsigned long long)\result * 10) / 100) == b);
*/
long long func(unsigned long long a, unsigned long long b)
{
    unsigned long long x = 1;
    /*@
        loop invariant 1 <= x && x <= 1001;
        loop invariant (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
        loop assigns x;
        loop variant 1001 - x;
    */
    while (x <= 1000)
    {
        unsigned long long ta = x * 8;
        unsigned long long tb = x * 10;
        bool ok = true;
        
        unsigned long long ta_div_100 = 0;
        unsigned long long temp_ta = ta;
        /*@
            loop invariant 0 <= temp_ta && temp_ta <= x * 8;
            loop invariant 0 <= ta_div_100 && ta_div_100 <= (x * 8) / 100;
            loop invariant temp_ta == x * 8 - ta_div_100 * 100;
            loop assigns temp_ta, ta_div_100;
            loop variant temp_ta;
        */
        while (temp_ta >= 100)
        {
            temp_ta -= 100;
            ta_div_100 += 1;
        }
        ta = ta_div_100;
        
        unsigned long long tb_div_100 = 0;
        unsigned long long temp_tb = tb;
        /*@
            loop invariant 0 <= temp_tb && temp_tb <= x * 10;
            loop invariant 0 <= tb_div_100 && tb_div_100 <= (x * 10) / 100;
            loop invariant temp_tb == x * 10 - tb_div_100 * 100;
            loop assigns temp_tb, tb_div_100;
            loop variant temp_tb;
        */
        while (temp_tb >= 100)
        {
            temp_tb -= 100;
            tb_div_100 += 1;
        }
        tb = tb_div_100;
        
        if (ta != a || tb != b)
        {
            ok = false;
        }
        
        if (ok)
        {
            //@ assert ta == a && tb == b;
            return (long long)x;
        }
        x += 1;
    }
    return -1;
}
