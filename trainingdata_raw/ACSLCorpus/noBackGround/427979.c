#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (b >= a);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool answer = false;
    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    
    if (b >= a)
    {
        answer = true;
    }
    
    //@ assert answer == (b >= a);
    return answer;
}
