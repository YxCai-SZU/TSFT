#include <stdint.h>

/*@
    predicate is_triangular(integer n, integer ret) =
        n >= 0 && n < 1000 && ret == n * (n + 1) / 2 && ret >= n;

    lemma triangular_bound:
        \forall integer n; n >= 0 && n < 1000 ==> n * (n + 1) / 2 >= n;
*/

/*@
    requires n < 1000;
    ensures \result == n * (n + 1) / 2;
    ensures \result >= n;
    assigns \nothing;
*/
uint32_t is_triangular(uint32_t n)
{
    //@ assert n >= 0;
    //@ assert n < 1000;
    //@ assert n * (n + 1) / 2 <= (1000 * (1000 + 1)) / 2;
    //@ assert n * (n + 1) / 2 >= n;
    
    return n * (n + 1) / 2;
}

int main()
{
    return 0;
}
