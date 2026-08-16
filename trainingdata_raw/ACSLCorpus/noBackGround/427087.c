#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100);
    ensures ((\result) >= 0);
    ensures ((\result) == (((A)) - (((B)) * 2)) || (\result) == 0);
*/
int func(int A, int B)
{
    int answer;
    
    answer = A - (B * 2);
    
    //@ assert answer == ((A) - ((B) * 2));
    
    if (answer < 0)
    {
        answer = 0;
    }
    
    //@ assert ((answer) >= 0);
    //@ assert ((answer) == (((A)) - (((B)) * 2)) || (answer) == 0);
    
    return answer;
}
