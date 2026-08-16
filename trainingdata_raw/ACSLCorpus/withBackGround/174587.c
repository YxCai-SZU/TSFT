#include <stdint.h>

/*@
    predicate condition_holds(integer N, integer result) =
        result == 1 ==> N % 100 <= 5 * (N / 100);
    predicate condition_fails(integer N, integer result) =
        result == 0 ==> N % 100 > 5 * (N / 100);
    lemma mod_bound: \forall integer N; 1 <= N <= 1000000000 ==> N % 100 <= N;
    lemma div_bound: \forall integer N; 1 <= N <= 1000000000 ==> N / 100 * 5 <= 5 * (N / 100);
*/

/*@
    requires 1 <= N <= 1000000000;
    ensures \result == 0 || \result == 1;
    ensures condition_holds(N, \result);
    ensures condition_fails(N, \result);
*/
uint32_t func(uint32_t N)
{
    uint32_t n_mod_100;
    uint32_t n_div_100;
    uint32_t answer;

    //@ assert N % 100 <= N;
    //@ assert N / 100 * 5 <= 5 * (N / 100);

    n_mod_100 = N % 100;
    n_div_100 = (N / 100) * 5;
    answer = 0;

    if (n_mod_100 <= n_div_100)
    {
        answer = 1;
        //@ assert answer == 1;
        //@ assert N % 100 <= 5 * (N / 100);
    }
    else
    {
        //@ assert answer == 0;
        //@ assert N % 100 > 5 * (N / 100);
    }

    return answer;
}
