#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= N && N <= 100;
    requires ((N) >= 1 && (N) <= 100 &&
        \valid((X_N) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> 1 <= (X_N)[i] && (X_N)[i] <= 100);
    ensures 0 <= \result && \result <= N;
    assigns \nothing;
*/
int func(int N, int *X_N) {
    int count = 0;
    int index = 0;
    int sum = 0;
    
    /*@
        loop invariant 0 <= index <= N;
        loop invariant 0 <= count <= index;
        loop invariant sum <= 100 * index;
        loop invariant \forall integer i; 0 <= i < index ==> 1 <= X_N[i] && X_N[i] <= 100;
        loop invariant ((N) >= 1 && (N) <= 100 &&
        \valid((X_N) + (0 .. (N)-1)) &&
        \forall integer i; 0 <= i < (N) ==> 1 <= (X_N)[i] && (X_N)[i] <= 100);
        loop assigns count, index, sum;
        loop variant N - index;
    */
    while (index < N && sum <= 0) {
        //@ assert 0 <= index < N;
        sum += X_N[index];
        //@ assert sum <= 100 * (index + 1);
        count += 1;
        //@ assert 0 <= count <= index + 1;
        index += 1;
        //@ assert 0 <= index <= N;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
