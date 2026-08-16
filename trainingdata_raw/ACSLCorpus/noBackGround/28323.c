#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100) && (0 <= (c) && (c) <= 100);
    ensures (0 <= (\result) && (\result) <= 200);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans = 0;
    //@ assert ((ans) >= 0);
    
    if (c > 0)
    {
        if (b < c)
        {
            ans += b * 2 + 1;
            //@ assert ((ans) >= 0);
            
            int c_temp = c - (b + 1);
            //@ assert ((c_temp) >= 0);
            
            int a_temp = (a > 1) ? (a - 1) : 0;
            //@ assert ((a_temp) >= 0);
            
            int add_val = (a_temp + 1 < c_temp) ? (a_temp + 1) : c_temp;
            //@ assert ((add_val) >= 0);
            
            ans += add_val;
            //@ assert ((ans) >= 0);
        }
        else
        {
            ans += c * 2;
            //@ assert ((ans) >= 0);
        }
    }
    
    //@ assert ans <= 200;
    return ans;
}
