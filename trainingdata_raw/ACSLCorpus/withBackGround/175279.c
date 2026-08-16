#include <limits.h>

/*@
    predicate valid_range(integer N, integer i) =
        1 <= N && N <= 100 &&
        1 <= i && i <= N;

    logic integer compute_j(integer N, integer i) = N - i + 1;
*/

/*@
    requires valid_range(N, i);
    ensures 1 <= \result && \result <= N;
    ensures \result == compute_j(N, i);
    assigns \nothing;
*/
int func(int N, int i)
{
    int answer;
    //@ assert valid_range(N, i);
    answer = N - i + 1;
    //@ assert answer == compute_j(N, i);
    return answer;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    int result;
    
    result = func(10, 5);
    //@ assert result == 6;
    assert(result == 6);
    
    result = func(15, 8);
    //@ assert result == 8;
    assert(result == 8);
    
    result = func(20, 20);
    //@ assert result == 1;
    assert(result == 1);
    
    return 0;
}
#endif
