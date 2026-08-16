#include <stdint.h>

/*@ predicate ans_nonnegative(integer a) = a >= 0; */
/*@ predicate temp_in_range(integer t, integer N) = 0 <= t <= N; */
/*@ predicate invariant_relation(integer a, integer t, integer N) = a * 3 + t == N; */
/*@ predicate N_in_range(integer N) = 1 <= N <= 1000; */

/*@ lemma ans_bound: \forall integer ans, N; 
      invariant_relation(ans, 0, N) ==> ans * 3 <= N; */
/*@ lemma ans_upper_bound: \forall integer ans, N; 
      invariant_relation(ans, 0, N) && N_in_range(N) ==> N < (ans + 1) * 3; */

/*@ requires 1 <= N <= 1000;
    ensures \result >= 0;
    ensures \result * 3 <= N;
    ensures N < (\result + 1) * 3;
    assigns \nothing;
 */
int64_t func(int64_t N)
{
    int64_t ans = 0;
    int64_t temp = N;
    int64_t divisor = 3;

    /*@ loop invariant 0 <= ans;
        loop invariant 0 <= temp <= N;
        loop invariant ans * 3 + temp == N;
        loop invariant 1 <= N <= 1000;
        loop assigns ans, temp;
        loop variant temp;
     */
    while (temp >= divisor)
    {
        //@ assert temp >= 3;
        temp -= divisor;
        ans += 1;
        //@ assert ans * 3 + temp == N;
    }

    //@ assert ans * 3 <= N;
    //@ assert N < (ans + 1) * 3;

    return ans;
}
