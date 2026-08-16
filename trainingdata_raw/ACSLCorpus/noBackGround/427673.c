#include <stddef.h>
#include <stdlib.h>

/*@
    requires ((N) >= 2 && (N) <= 200000 &&
        \valid((input_vec) + (0 .. (N)-2)) &&
        \forall integer j; 0 <= j < (N)-1 ==> 
            (input_vec)[j] >= 1 && (input_vec)[j] < j + 1);
    ensures \valid(\result + (0 .. N-1));
    ensures \forall integer i; 0 <= i < N ==> \result[i] >= 0;
    assigns \nothing;
*/
int* func(size_t N, const int* input_vec) {
    int* result;
    size_t i;
    size_t index;
    int v;
    int new_value;
    
    result = (int*)malloc(N * sizeof(int));
    if (!result) return NULL;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= N;
        loop invariant \forall integer j; 0 <= j < i ==> result[j] == 0;
        loop invariant \valid(result + (0 .. N-1));
        loop assigns i, result[0 .. N-1];
        loop variant N - i;
    */
    while (i < N) {
        //@ assert i < N;
        result[i] = 0;
        i++;
    }
    
    index = 0;
    /*@
        loop invariant 0 <= index <= N-1;
        loop invariant \valid(result + (0 .. N-1));
        loop invariant \valid(input_vec + (0 .. N-2));
        loop invariant \forall integer j; 0 <= j < N-1 ==> 
            input_vec[j] >= 1 && input_vec[j] < j + 1;
        loop invariant \forall integer j; 0 <= j < N ==> result[j] >= 0;
        loop invariant \forall integer j; 0 <= j < N ==> result[j] <= index;
        loop assigns index, result[0 .. N-1];
        loop variant (N-1) - index;
    */
    while (index < N - 1) {
        //@ assert index < N-1;
        v = input_vec[index];
        //@ assert v >= 1 && v < index + 1;
        new_value = result[v - 1] + 1;
        result[v] = new_value;
        index++;
    }
    
    return result;
}
