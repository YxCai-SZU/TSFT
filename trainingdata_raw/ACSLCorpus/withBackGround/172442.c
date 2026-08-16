#include <stdbool.h>

/*@
    predicate is_valid_range(integer N) =
        1 <= N && N <= 10000;

    logic integer division_by_1000(integer N, integer temp_N) =
        (N - temp_N) / 1000;

    logic integer division_by_100(integer N, integer temp_N) =
        (N - temp_N) / 100;

    lemma division_property_1000:
        \forall integer N, temp_N;
            is_valid_range(N) && 0 <= temp_N && temp_N <= N ==>
            division_by_1000(N, temp_N) == (N - temp_N) / 1000;

    lemma division_property_100:
        \forall integer N, temp_N;
            is_valid_range(N) && 0 <= temp_N && temp_N <= N ==>
            division_by_100(N, temp_N) == (N - temp_N) / 100;
*/

/*@
    requires 1 <= N && N <= 10000;
    ensures \result == 1000 * (N / 1000) || \result == 100 * (N / 100);
    assigns \nothing;
*/
int func(int N)
{
    int result;
    int temp_N;
    int count;

    result = 0;
    temp_N = N;
    count = 0;

    /*@
        loop invariant 1 <= N && N <= 10000;
        loop invariant 0 <= temp_N && temp_N <= N;
        loop invariant count == division_by_1000(N, temp_N);
        loop invariant temp_N == N - 1000 * count;
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 1000)
    {
        //@ assert temp_N >= 1000;
        temp_N -= 1000;
        count += 1;
    }

    if (count == 0)
    {
        count = 0;
        temp_N = N;
        /*@
            loop invariant 1 <= N && N <= 10000;
            loop invariant 0 <= temp_N && temp_N <= N;
            loop invariant count == division_by_100(N, temp_N);
            loop invariant temp_N == N - 100 * count;
            loop assigns temp_N, count;
            loop variant temp_N;
        */
        while (temp_N >= 100)
        {
            //@ assert temp_N >= 100;
            temp_N -= 100;
            count += 1;
        }
        result = 100 * count;
    }
    else
    {
        result = 1000 * count;
    }

    //@ assert result == 1000 * (N / 1000) || result == 100 * (N / 100);
    return result;
}
