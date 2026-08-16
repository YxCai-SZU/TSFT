#include <limits.h>
#include <stdbool.h>

/*@
    predicate valid_array(int *arr, integer N) =
        N > 0 && N <= 100 &&
        \forall integer i; 0 <= i < N ==> 0 <= arr[i] && arr[i] <= 100;

    logic integer min_value(integer sum, integer min) =
        sum < min ? sum : min;
*/

/*@
    requires N > 0 && N <= 100;
    requires \valid(X_N + (0 .. N-1));
    requires valid_array(X_N, N);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int N, int *X_N)
{
    int min = INT_MAX;
    int sum = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= N;
        loop invariant sum >= 0;
        loop invariant sum <= i;
        loop invariant min >= 0;
        loop invariant valid_array(X_N, N);
        loop assigns i, sum, min;
        loop variant N - i;
    */
    while (i < N)
    {
        int X = X_N[i];
        int abs_X = X < 0 ? -X : X;
        bool is_even = (abs_X & 1) == 0;

        if (is_even)
        {
            sum += 1;
        }
        else
        {
            //@ assert sum >= 0 && min >= 0;
            if (sum < min)
            {
                min = sum;
            }
            sum = 0;
        }
        i += 1;
    }

    //@ assert sum >= 0 && min >= 0;
    if (sum < min)
    {
        min = sum;
    }

    //@ assert min >= 0;
    return min;
}
