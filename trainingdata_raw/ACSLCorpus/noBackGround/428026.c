#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures ((\result) >= 0 || (\result) == -1);
    ensures ((\result) >= 0 ==> (\result) * 8 / 100 == (n));
    assigns \nothing;
*/
int func(int n)
{
    int x = -1;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 1000;
        loop invariant x == -1 || (x >= 0 && x * 8 / 100 == n);
        loop invariant (1 <= (n) && (n) <= 100);
        loop assigns x, i;
        loop variant 1000 - i;
    */
    while (i < 1000)
    {
        int cur = i * 8;
        int div = 0;
        int mod_val = cur;
        
        /*@
            loop invariant 0 <= mod_val <= cur;
            loop invariant 0 <= div <= cur / 100;
            loop invariant mod_val == cur - div * 100;
            loop invariant cur == i * 8;
            loop assigns mod_val, div;
            loop variant mod_val;
        */
        while (mod_val >= 100)
        {
            mod_val -= 100;
            div += 1;
        }
        
        //@ assert div == (i * 8) / 100;
        
        if (div == n)
        {
            x = i;
            break;
        }
        
        i += 1;
    }
    
    //@ assert x == -1 || (x >= 0 && x * 8 / 100 == n);
    return x;
}
