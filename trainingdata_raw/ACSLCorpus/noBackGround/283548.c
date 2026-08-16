#include <limits.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (c) <= 20) && (1 <= (d) <= 20);
    ensures \result == (a - b + c - d) || \result == -(a - b + c - d);
*/
int func(int a, int b, int c, int d)
{
    int answer;
    
    answer = a - b + c - d;
    
    if (answer < 0)
    {
        answer = -answer;
    }
    
    //@ assert answer == (a - b + c - d) || answer == -(a - b + c - d);
    
    return answer;
}
