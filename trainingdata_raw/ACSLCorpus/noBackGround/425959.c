#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100);
    ensures ((\result) >= 0 &&
        (\result) <= (A) &&
        ((\result) == (((A)) - (((B)) * 2)) || (\result) == 0));
*/
int func(int A, int B)
{
    int C;
    int result;

    C = A - (B * 2);
    
    //@ assert C == ((A) - ((B) * 2));
    
    if (C > 0)
    {
        //@ assert C >= 0;
        //@ assert C <= A;
        result = C;
    }
    else
    {
        //@ assert 0 >= 0;
        //@ assert 0 <= A;
        result = 0;
    }
    
    //@ assert ((result) >= 0 &&         (result) <= (A) &&         ((result) == (((A)) - (((B)) * 2)) || (result) == 0));
    return result;
}
