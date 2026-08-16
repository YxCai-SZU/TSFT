#include <stdbool.h>
#include <stddef.h>

/*@
    requires 2 <= N <= 100000;
    requires \valid(A + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> 1 <= A[i] <= N;
    requires \forall integer i, j; 0 <= i < j < N ==> A[i] != A[j];
    assigns \nothing;
    ensures 0 <= \result <= N;
*/
int func(size_t N, int *A)
{
    int num = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant 0 <= num <= i;
        loop invariant (2 <= (N) <= 100000 &&
        \valid((A) + (0 .. (N)-1)) &&
        (\forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] <= (N)) &&
        (\forall integer i, j; 0 <= i < j < (N) ==> (A)[i] != (A)[j]));
        loop assigns i, num;
        loop variant N - i;
    */
    while (i < N)
    {
        if ((int)(i + 1) == A[i])
        {
            num += 1;
        }
        i += 1;
        
        //@ assert 0 <= num <= i;
    }
    
    //@ assert 0 <= num <= N;
    return num;
}
