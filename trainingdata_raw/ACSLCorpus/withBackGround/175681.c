#include <stdbool.h>

/*@
    predicate is_square(integer n, integer result) =
        result == n * n;

    lemma square_range:
        \forall integer n;
        -46340 <= n <= 46340 ==> -46340 * 46340 <= n * n <= 46340 * 46340;
*/

/*@
    requires -46340 <= n <= 46340;
    ensures \result == n * n;
    ensures -46340 * 46340 <= \result <= 46340 * 46340;
*/
int square(int n)
{
    //@ assert -46340 <= n && n <= 46340;
    //@ assert -46340 * 46340 <= n * n && n * n <= 46340 * 46340;
    return n * n;
}

int main()
{
    int n;
    int x;
    
    n = 3;
    x = square(n);
    //@ assert x == 9;
    //@ assert 0 <= x <= 9;
    
    return 0;
}
