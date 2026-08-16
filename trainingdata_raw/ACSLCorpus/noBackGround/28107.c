#include <stdbool.h>

/*@
    requires (1 <= (a) <= 500 &&
        1 <= (b) <= 500 &&
        1 <= (c) <= 1000);
    ensures \result == (((a) + (b)) >= c);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool state;
    unsigned long long sum;

    state = false;
    //@ assert (1 <= (a) <= 500 &&         1 <= (b) <= 500 &&         1 <= (c) <= 1000);
    //@ assert ((a) + (b)) <= 1000;
    sum = a + b;
    
    if (sum >= c)
    {
        state = true;
    }
    
    return state;
}
