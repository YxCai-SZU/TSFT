#include <stdbool.h>

/*@
    requires 1 <= a <= 13;
    requires 1 <= b <= 13;
    requires 1 <= c <= 13;
    ensures \result == true <==> (a + b + c <= 21);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;

    //@ assert a + b <= 26;
    //@ assert a + b + c <= 39;
    
    sum = a + b + c;
    
    //@ assert sum <= 39;
    
    return sum <= 21;
}
