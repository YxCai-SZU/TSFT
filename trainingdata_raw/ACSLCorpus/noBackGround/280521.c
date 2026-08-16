#include <stdbool.h>

/*@
    requires (1 <= (N) <= 100);
    requires (1 <= (M) <= 100);
    requires \valid_read(X_N + (0..N-1));
    requires \valid_read(A_M + (0..M-1));
    requires (\forall integer i; 0 <= i < (N) ==> (1 <= ((X_N)[i]) <= 1000));
    requires (\forall integer i; 0 <= i < (M) ==> (1 <= ((A_M)[i]) <= 1000));
    assigns \nothing;
    ensures 0 <= \result <= ((N) * 1000);
*/
int func(int N, int *X_N, int M, int *A_M)
{
    int ans = 0;
    int x_index = 0;
    
    /*@
        loop invariant 0 <= x_index <= N;
        loop invariant 0 <= ans <= ((x_index) * 1000);
        loop invariant (\forall integer i; 0 <= i < (N) ==> (1 <= ((X_N)[i]) <= 1000));
        loop invariant (\forall integer i; 0 <= i < (M) ==> (1 <= ((A_M)[i]) <= 1000));
        loop invariant (1 <= (N) <= 100);
        loop invariant (1 <= (M) <= 100);
        loop assigns ans, x_index;
        loop variant N - x_index;
    */
    while (x_index < N)
    {
        int x = X_N[x_index];
        bool contains = false;
        int a_index = 0;
        
        /*@
            loop invariant 0 <= a_index <= M;
            loop invariant (\forall integer i; 0 <= i < (M) ==> (1 <= ((A_M)[i]) <= 1000));
            loop invariant (1 <= (N) <= 100);
            loop assigns contains, a_index;
            loop variant M - a_index;
        */
        while (a_index < M)
        {
            if (A_M[a_index] == x)
            {
                contains = true;
                break;
            }
            a_index++;
        }
        
        if (!contains)
        {
            //@ assert 1 <= x <= 1000;
            ans += x;
            //@ assert 0 <= ans <= ((x_index + 1) * 1000);
        }
        
        x_index++;
    }
    
    //@ assert 0 <= ans <= ((N) * 1000);
    return ans;
}
