#include <stddef.h>

/*@
    predicate valid_range(integer n) =
        1 <= n && n <= 100;
*/

/*@
    logic integer loop_decrease(integer n, integer i) =
        n + 1 - i;
*/

/*@
    lemma loop_progress:
        \forall integer n, i;
            valid_range(n) && 1 <= i && i <= n + 1 && i < n + 1 ==>
            loop_decrease(n, i) > loop_decrease(n, i + 1);
*/

/*@
    requires valid_range(n);
    ensures \result <= n;
    ensures \result >= 1;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans = 1;
    size_t i = 1;

    /*@
        loop invariant 1 <= i && i <= n + 1;
        loop invariant ans <= n;
        loop invariant ans >= 1;
        loop assigns i, ans;
        loop variant n + 1 - i;
    */
    while (i < n + 1)
    {
        //@ assert 1 <= i && i <= n + 1;
        if (n % i == 0)
        {
            ans = i;
        }
        i += 1;
    }
    //@ assert ans <= n;
    //@ assert ans >= 1;
    return ans;
}

int main()
{
    return 0;
}
