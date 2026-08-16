/*@
    predicate valid_input(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;
        
    logic integer compute_result(integer n, integer a) = n * n - a;
    
    lemma no_overflow: \forall integer n; 1 <= n <= 100 ==> n * n <= 100 * 100;
*/

/*@
    requires valid_input(n, a);
    ensures \result == compute_result(n, a);
    assigns \nothing;
*/
int func(int n, int a)
{
    // Variable declarations at top
    int result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    //@ assert n * n <= 100 * 100;
    
    result = n * n - a;
    return result;
}

#ifdef TEST
#include <assert.h>

void test1(void)
{
    int n = 5;
    int a = 3;
    int result = func(n, a);
    //@ assert result == compute_result(n, a);
    assert(result == n * n - a);
}

int main(void)
{
    test1();
    return 0;
}
#endif
