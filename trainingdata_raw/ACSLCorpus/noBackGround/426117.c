#include <stdbool.h>
#include <limits.h>

/*@ requires N > 0 && N <= 100;
    requires \valid(A + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> A[i] > 0 && A[i] <= 1000;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int N, int *A) {
    int ans = INT_MAX;
    int a_index = 0;
    
    /*@ loop invariant 0 <= a_index <= N;
        loop invariant ans >= 0;
        loop invariant \forall integer i; 0 <= i < N ==> A[i] > 0 && A[i] <= 1000;
        loop invariant N > 0 && N <= 100;
        loop assigns ans, a_index;
        loop variant N - a_index;
    */
    while (a_index < N) {
        int a = A[a_index];
        int b = (a >> 31) != 0 ? 0 : a;
        int c = (a >> 31) != 0 ? a + b : 0;
        int x = (a >> 31) != 0 ? a + c : b;
        int y = (a >> 31) != 0 ? b : a + c;
        
        //@ assert a > 0 && a <= 1000;
        //@ assert b >= 0;
        //@ assert c >= 0;
        //@ assert x >= 0;
        //@ assert y >= 0;
        
        ans = ans < x ? ans : x;
        a_index++;
    }
    
    //@ assert ans >= 0;
    return ans;
}
