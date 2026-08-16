#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_array(integer N, int *a) =
        N > 0 &&
        \valid(a + (0 .. N-1)) &&
        \forall integer i; 0 <= i < N ==> a[i] > 0 && a[i] <= 1000000000;

    logic integer count_condition(integer prev, integer a_i) =
        prev <= a_i ? 1 : 0;

    lemma count_bound:
        \forall integer N, int *a, integer i, integer count;
        valid_array(N, a) &&
        0 <= i <= N &&
        0 <= count <= i &&
        (\forall integer j; 0 <= j < i ==> a[j] > 0 && a[j] <= 1000000000)
        ==>
        count <= N;
*/


size_t func(size_t N, const int *a)
{
    int prev = 0;
    size_t count = 0;
    size_t i = 0;

    
    while (i < N)
    {
        int a_i = a[i];
        if (prev <= a_i)
        {
            count += 1;
        }
        else
        {
            prev = a_i;
        }
        i += 1;
    }

    //@ assert count <= N;
    return count;
}
