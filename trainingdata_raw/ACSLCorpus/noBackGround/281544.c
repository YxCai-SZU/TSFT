#include <stdbool.h>

/*@
    requires (1 <= (N) <= 100 && 1 <= (i) <= (N));
    ensures \result == ((N) - (i) + 1);
    ensures (1 <= (\result) <= (N));
*/
int func(int N, int i)
{
    int j;
    int answer;

    //@ assert (1 <= (N) <= 100 && 1 <= (i) <= (N));
    
    answer = N - i + 1;
    
    //@ assert answer == ((N) - (i) + 1);
    
    j = answer;
    
    //@ assert (1 <= (j) <= (N));
    
    return j;
}
