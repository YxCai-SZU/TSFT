#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/*@
    requires ((n) >= 2 && (n) <= 200000 &&
        \valid((v) + (0 .. (n)-2)) &&
        \forall integer i; 0 <= i < (n)-1 ==> (v)[i] >= 1 && (v)[i] < i + 1);
    ensures \valid(\result + (0 .. n-1)) && \forall integer i; 0 <= i < n ==> \result[i] >= 0;
*/
int* func(size_t n, int* v)
{
    int* result;
    size_t i;
    size_t index;
    int current_value;
    
    //@ assert n >= 2 && n <= 200000;
    result = (int*)malloc(n * sizeof(int));
    if (!result) return NULL;
    
    //@ ghost size_t loop1_i = 0;
    i = 0;
    /*@
        loop invariant (0 <= (loop1_i) && (loop1_i) <= (n) &&
        \valid((result) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (loop1_i) ==> (result)[j] == 0);
        loop invariant n >= 2 && n <= 200000;
        loop assigns i, result[0 .. n-1], loop1_i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert 0 <= i && i <= n;
        result[i] = 0;
        //@ assert \forall integer j; 0 <= j < i+1 ==> result[j] == 0;
        i++;
        //@ ghost loop1_i++;
    }
    
    //@ assert \forall integer j; 0 <= j < n ==> result[j] == 0;
    
    //@ ghost size_t loop2_idx = 0;
    index = 0;
    /*@
        loop invariant (0 <= (loop2_idx) && (loop2_idx) <= (n)-1 &&
        \valid((v) + (0 .. (n)-2)) &&
        \valid((result) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> (result)[j] >= 0 && (result)[j] <= (loop2_idx) &&
        \forall integer j; 0 <= j < (n)-1 ==> (v)[j] >= 1 && (v)[j] < j + 1);
        loop assigns index, result[0 .. n-1], loop2_idx;
        loop variant n-1 - index;
    */
    while (index < n-1)
    {
        //@ assert 0 <= index && index <= n-1;
        //@ assert v[index] >= 1 && v[index] < index + 1;
        size_t idx = (size_t)(v[index] - 1);
        //@ assert idx < n;
        current_value = result[idx];
        //@ assert current_value >= 0 && current_value <= index;
        result[idx] = current_value + 1;
        //@ assert result[idx] >= 1 && result[idx] <= index+1;
        index++;
        //@ ghost loop2_idx++;
    }
    
    //@ assert \forall integer j; 0 <= j < n ==> result[j] >= 0;
    return result;
}
