#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100);
    ensures \result == (k * 60 % 3 == 0 || k * 60 % 3 == 1 || k * 60 % 3 == 2);
*/
bool func(int k)
{
    int x;
    int x_mod_3;
    
    //@ assert (1 <= (k) && (k) <= 100);
    x = k * 60;
    x_mod_3 = x;
    
    /*@
        loop invariant 1 <= k && k <= 100;
        loop invariant x == k * 60;
        loop invariant x_mod_3 >= 0;
        loop invariant x_mod_3 <= x;
        loop invariant x_mod_3 == x || x_mod_3 % 3 == x % 3;
        loop assigns x_mod_3;
    */
    while (x_mod_3 >= 3)
    {
        //@ assert x_mod_3 >= 3;
        x_mod_3 -= 3;
    }
    
    /*@
        loop invariant 1 <= k && k <= 100;
        loop invariant x == k * 60;
        loop invariant x_mod_3 < 3;
        loop invariant x_mod_3 == x % 3;
        loop assigns x_mod_3;
    */
    while (x_mod_3 < 0)
    {
        //@ assert x_mod_3 < 0;
        x_mod_3 += 3;
    }
    
    //@ assert x_mod_3 == 0 || x_mod_3 == 1 || x_mod_3 == 2;
    return x_mod_3 == 0 || x_mod_3 == 1 || x_mod_3 == 2;
}
