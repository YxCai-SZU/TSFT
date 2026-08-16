#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (N) <= 1000000);
    requires \valid_read(input_vec + (0 .. N-1));
    requires ((N) == (N) &&
    \forall integer i; 0 <= i < (N) ==> (1 <= ((input_vec)[i]) <= 1000000000));
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= N;
    ensures \result == -1 ==> N > 0;
*/
int func(int N, int *input_vec) {
    int before = 0;
    int count = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= N;
        loop invariant 0 <= count <= index;
        loop invariant index > 0 ==> 
            \forall integer i; 0 <= i < index ==> (1 <= (input_vec[i]) <= 1000000000);
        loop invariant ((N) == (N) &&
    \forall integer i; 0 <= i < (N) ==> (1 <= ((input_vec)[i]) <= 1000000000));
        loop invariant (1 <= (N) <= 1000000);
        loop assigns before, count, index;
    */
    while (index < N) {
        int item = input_vec[index];
        
        //@ assert (1 <= (item) <= 1000000000);
        
        if (before >= item) {
            count = count + 1;
            before = item;
        } else {
            before = item;
        }
        
        index = index + 1;
    }
    
    if (count == 0) {
        //@ assert N > 0;
        return -1;
    } else {
        //@ assert count >= 0 && count <= N;
        return count;
    }
}
