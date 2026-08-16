#include <stdbool.h>
/*@
    requires 1 <= N <= 100;
    requires \valid(A+(0..N-1));
    requires \forall integer i; 0 <= i < N ==> 1 <= A[i] <= 1000;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (N) ==> 
            ((A)[i] % 2 == 0 ==> ((A)[i] % 3 == 0 || (A)[i] % 5 == 0)));
*/
bool func(int N, int *A) {
    bool flag = true;
    int i = 0;
    /*@
        loop invariant 0 <= i <= N;
        loop invariant flag == true <==> 
            \forall integer j; 0 <= j < i ==> 
                (A[j] % 2 == 0 ==> (A[j] % 3 == 0 || A[j] % 5 == 0));
        loop assigns i, flag;
        loop variant N - i;
    */
    while (i < N) {
        int a = A[i];
        if (a % 2 == 0) {
            if (!(a % 3 == 0 || a % 5 == 0)) {
                flag = false;
            }
        }
        i++;
    }
    return flag;
}
