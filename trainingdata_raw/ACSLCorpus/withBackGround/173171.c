#include <stdbool.h>

/*@
    predicate valid_range(integer n) =
        1 <= n && n <= 9;

    logic integer cube(integer n) =
        n * n * n;

    lemma cube_range:
        \forall integer n; valid_range(n) ==> 1 <= cube(n) && cube(n) <= 729;
*/

/*@
    requires valid_range(n);
    ensures \result == cube(n);
    assigns \nothing;
*/
int func(int n)
{
    int ans;
    //@ assert 1 <= n && n <= 9;
    //@ assert 1 <= n * n && n * n <= 81;
    //@ assert 1 <= n * n * n && n * n * n <= 729;
    ans = n * n * n;
    return ans;
}

int main()
{
    return 0;
}
