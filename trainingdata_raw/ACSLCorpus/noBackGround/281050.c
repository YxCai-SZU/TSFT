#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a * b * 2 >= 11);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int m;
    
    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    
    //@ assert 1 <= a * b <= 9;
    
    m = a * b * 2;
    
    //@ assert m == ((a) * (b) * 2);
    
    return m >= 11;
}
