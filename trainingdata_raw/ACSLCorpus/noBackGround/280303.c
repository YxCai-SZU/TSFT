#include <stddef.h>
#include <stdlib.h>

/*@
    requires (2 <= (N) && (N) <= 200000 &&
        \valid((A) + (0 .. (N)-2)) &&
        \forall integer i; 0 <= i < (N)-1 ==> 
            (A)[i] > 1 && (A)[i] < (N) && (A)[i] <= i + 1);
    assigns \nothing;
    ensures \valid(\result + (0 .. N-1));
    ensures \forall integer i; 0 <= i < N ==> \result[i] >= 0 && \result[i] <= N-1;
*/
size_t* func(size_t N, size_t* A) {
    size_t* v;
    size_t* result;
    size_t i;
    size_t index;
    size_t current_value;
    
    //@ assert (2 <= (N) && (N) <= 200000 &&         \valid((A) + (0 .. (N)-2)) &&         \forall integer i; 0 <= i < (N)-1 ==>              (A)[i] > 1 && (A)[i] < (N) && (A)[i] <= i + 1);
    
    v = (size_t*)malloc((N + 1) * sizeof(size_t));
    //@ assert \valid(v + (0 .. N));
    
    i = 0;
    /*@
        loop invariant 0 <= i <= N+1;
        loop invariant \forall integer j; 0 <= j < i ==> v[j] == 0;
        loop assigns i, v[0 .. N];
        loop variant N+1 - i;
    */
    while (i <= N) {
        //@ assert i <= N;
        v[i] = 0;
        i++;
    }
    //@ assert (\forall integer j; 0 <= j < (N+1) ==> (v)[j] == 0);
    
    i = 0;
    /*@
        loop invariant 0 <= i <= N-1;
        loop invariant \forall integer j; 0 <= j < N+1 ==> v[j] >= 0 && v[j] <= i;
        loop assigns i, v[0 .. N];
        loop variant N-1 - i;
    */
    while (i < N-1) {
        //@ assert A[i] > 1 && A[i] < N && A[i] <= i + 1;
        index = A[i] - 1;
        //@ assert 0 <= index < N+1;
        current_value = v[index];
        //@ assert current_value >= 0 && current_value <= i;
        v[index] = current_value + 1;
        //@ assert v[index] >= 0 && v[index] <= i+1;
        i++;
    }
    //@ assert (\forall integer k; 0 <= k < (N+1) ==> (v)[k] >= 0 && (v)[k] <= (N-1));
    
    result = (size_t*)malloc(N * sizeof(size_t));
    //@ assert \valid(result + (0 .. N-1));
    
    i = 0;
    /*@
        loop invariant 0 <= i <= N;
        loop invariant \forall integer j; 0 <= j < i ==> result[j] == v[j];
        loop assigns i, result[0 .. N-1];
        loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i < N;
        result[i] = v[i];
        i++;
    }
    //@ assert \forall integer j; 0 <= j < N ==> result[j] == v[j];
    
    free(v);
    //@ assert \forall integer i; 0 <= i < N ==> result[i] >= 0 && result[i] <= N-1;
    return result;
}
