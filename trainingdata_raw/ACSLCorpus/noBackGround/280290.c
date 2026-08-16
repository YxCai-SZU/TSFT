#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures (a > 9 || b > 9) ==> \result == -1;
    ensures (a <= 9 && b <= 9) ==> \result == (int)(a * b);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    int result;
    
    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    
    if (a > 9 || b > 9)
    {
        result = -1;
        //@ assert (a > 9 || b > 9) ==> result == -1;
        return result;
    }
    
    //@ assert a <= 9 && b <= 9;
    //@ assert 1 <= a * b && a * b <= 81;
    
    result = (int)(a * b);
    //@ assert (a <= 9 && b <= 9) ==> result == (int)(a * b);
    return result;
}
