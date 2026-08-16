#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 13) && (1 <= (b) && (b) <= 13) && (1 <= (c) && (c) <= 13);
    ensures \result == (a + b + c >= 22);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    
    //@ assert (1 <= (a) && (a) <= 13);
    //@ assert (1 <= (b) && (b) <= 13);
    //@ assert (1 <= (c) && (c) <= 13);
    
    sum = a + b + c;
    
    //@ assert 3 <= sum && sum <= 39;
    
    if (sum >= 22)
    {
        return true;
    }
    else
    {
        return false;
    }
}
