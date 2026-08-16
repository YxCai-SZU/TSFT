#include <limits.h>

/*@
    requires (1 <= (N) <= 100 && 1 <= (i) <= (N));
    ensures 1 <= \result <= N;
    ensures \result == ((N) - ((i) - 1));
    assigns \nothing;
*/
int func(int N, int i)
{
    int answer;
    
    //@ assert 1 <= i && i <= N;
    //@ assert N - (i - 1) >= 1;
    
    answer = N - (i - 1);
    
    //@ assert answer == ((N) - ((i) - 1));
    //@ assert 1 <= answer && answer <= N;
    
    return answer;
}
