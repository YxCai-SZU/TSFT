#include <limits.h>

/*@
    predicate bounds(integer A, integer P) =
        0 <= A <= 100 && 0 <= P <= 100;

    logic integer total_sum(integer A, integer P) = A * 3 + P;

    lemma sum_bounds:
        \forall integer A, P; bounds(A, P) ==> 0 <= total_sum(A, P) <= 400;
*/

/*@
    requires bounds(A, P);
    ensures \result >= 0;
    ensures \result <= total_sum(A, P);
    assigns \nothing;
*/
int func(int A, int P)
{
    int sum;
    int ans;
    int temp_sum;
    int count;

    //@ assert bounds(A, P);
    sum = A * 3 + P;
    //@ assert 0 <= sum <= 400;

    ans = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= total_sum(A, P);
        loop invariant 0 <= count <= (total_sum(A, P) - temp_sum) / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant bounds(A, P);
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
        //@ assert temp_sum >= 0;
    }

    ans = count;

    //@ assert ans >= 0;
    //@ assert ans <= total_sum(A, P);
    //@ assert temp_sum >= 0;
    //@ assert temp_sum <= total_sum(A, P);

    return ans;
}
