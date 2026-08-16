#include <stdint.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures \result + a + b == 6;
    ensures \result == 1 || \result == 2 || \result == 3;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t answer;
    
    answer = 6 - a - b;
    
    //@ assert answer == 6 - a - b;
    
    if (answer < 0)
    {
        answer = -answer;
    }
    
    //@ assert answer == ((6 - (a) - (b)) < 0 ? -(6 - (a) - (b)) : (6 - (a) - (b)));
    
    if (answer == 1)
    {
        answer = 1;
    }
    else if (answer == 2)
    {
        answer = 2;
    }
    else if (answer == 3)
    {
        answer = 3;
    }
    
    //@ assert answer + a + b == 6;
    //@ assert answer == 1 || answer == 2 || answer == 3;
    
    return answer;
}
