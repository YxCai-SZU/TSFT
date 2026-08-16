#include <stdbool.h>
#include <stddef.h>

/*@ requires 3 <= N <= 100;
    requires 1 <= A <= 1000;
    requires 1 <= B <= 1000;
    requires \valid(X + (0 .. N-1));
    requires (\forall integer j; 0 <= j < (N) ==> 1 <= (X)[j] <= 1000);
    requires (\forall integer j; 0 <= j < (N) - 1 ==> (X)[j] < (X)[j + 1]);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= N * 1000;
*/
int func(int N, int A, int B, int *X) {
    int ans = 0;
    int i = 1;
    
    /*@ loop invariant 1 <= i <= N;
        loop invariant 0 <= ans;
        loop invariant ans <= i * 1000;
        loop invariant (\forall integer j; 0 <= j < (N) ==> 1 <= (X)[j] <= 1000);
        loop invariant (\forall integer j; 0 <= j < (N) - 1 ==> (X)[j] < (X)[j + 1]);
        loop assigns ans, i;
        loop variant N - i;
    */
    while (i < N) {
        int dist = X[i] - X[i - 1];
        
        if (dist <= B) {
            ans += 1;
        } else {
            ans += A;
        }
        
        //@ assert 0 <= ans;
        //@ assert ans <= (i + 1) * 1000;
        
        i += 1;
    }
    
    //@ assert ans >= 0;
    return ans;
}
