#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool ans;
    int a_mod, b_mod, sum_mod;
    
    //@ assert a + b <= 200;
    a_mod = a % 3;
    //@ assert a_mod == a % 3;
    b_mod = b % 3;
    //@ assert b_mod == b % 3;
    sum_mod = (a + b) % 3;
    //@ assert sum_mod == (a + b) % 3;
    
    ans = false;
    if (a_mod == 0 || b_mod == 0 || sum_mod == 0)
    {
        ans = true;
    }
    return ans;
}
