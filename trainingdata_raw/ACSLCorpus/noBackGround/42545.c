#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    ensures \result == true <==> ((x) % 2 != 0);
    assigns \nothing;
*/
bool func(int x)
{
    int remainder;
    
    //@ assert 1 <= x <= 100;
    
    remainder = x;
    
    /*@
        loop invariant 0 <= remainder <= x;
        loop invariant remainder % 2 == x % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
    }
    
    //@ assert remainder == 0 || remainder == 1;
    //@ assert remainder % 2 == x % 2;
    
    if (remainder != 0)
    {
        //@ assert ((x) % 2 != 0);
        return true;
    }
    else
    {
        //@ assert !((x) % 2 != 0);
        return false;
    }
}
