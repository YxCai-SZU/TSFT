#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures \result + a + b == 6;
    assigns \nothing;
*/
int func(int a, int b)
{
    int answer;
    
    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    
    answer = 6 - a - b;
    
    //@ assert answer == (6 - (a) - (b));
    
    //@ assert answer + a + b == 6;
    
    return answer;
}
