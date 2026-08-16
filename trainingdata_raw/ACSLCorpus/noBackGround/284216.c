#include <stdbool.h>

/*@
    requires (1 <= (N) <= 100 && 1 <= (i) <= (N));
    ensures 1 <= \result <= N;
    ensures \result == ((N) - (i) + 1);
    assigns \nothing;
*/
int func(int N, int i)
{
    //@ assert (1 <= (N) <= 100 && 1 <= (i) <= (N));
    int j;
    
    //@ assert 1 <= ((N) - (i) + 1) <= N;
    j = N - i + 1;
    
    //@ assert j == ((N) - (i) + 1);
    return j;
}
