#include <stdbool.h>

/*@
    requires (1 <= (N) <= 100 && 1 <= (i) <= (N));
    ensures 1 <= \result <= N;
    ensures \result == ((N) - ((i) - 1));
    assigns \nothing;
*/
int func(int N, int i)
{
    int answer;
    
    //@ assert (1 <= (N) <= 100 && 1 <= (i) <= (N));
    
    answer = N - (i - 1);
    
    //@ assert 1 <= answer <= N;
    //@ assert answer == ((N) - ((i) - 1));
    
    return answer;
}
