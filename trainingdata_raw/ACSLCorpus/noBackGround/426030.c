#include <stdbool.h>

/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    ensures \result >= 0;
    ensures \result == x - (y * 2) || \result == 0;
*/
int func(int x, int y)
{
    int answer;
    
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);
    //@ assert y * 2 <= 200;
    //@ assert x - (y * 2) >= -199;
    
    answer = x - (y * 2);
    
    if (answer < 0)
    {
        answer = 0;
    }
    
    return answer;
}
