#include <stdbool.h>
#include <limits.h>

/*@
 requires (2 <= (N) <= 100000 &&
     \valid((A) + (0 .. (N)-1)) &&
     \forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] <= (N) &&
     \forall integer i, j; 0 <= i < j < (N) ==> (A)[i] != (A)[j]);
 ensures \result >= 1 || \result == -1;
 ensures \result <= N;
 assigns \nothing;
*/
int func(int N, int *A) {
    unsigned int min = UINT_MAX;
    int min_index = 0;
    int index = 0;
    int next = 1;

    /*@
     loop invariant (0 <= (index) <= (N)-1 &&
     1 <= (next) <= (index)+1 &&
     (min) <= UINT_MAX &&
     (min_index) <= (index) &&
     (2 <= ((N)) <= 100000 &&
     \valid(((A)) + (0 .. ((N))-1)) &&
     \forall integer i; 0 <= i < ((N)) ==> 1 <= ((A))[i] <= ((N)) &&
     \forall integer i, j; 0 <= i < j < ((N)) ==> ((A))[i] != ((A))[j]) &&
     ((min) < UINT_MAX ==> (min) >= 1));
     loop assigns index, next, min, min_index;
     loop variant N - index;
    */
    while (index < N - 1) {
        //@ assert (0 <= (index) <= (N)-1 &&      1 <= (next) <= (index)+1 &&      (min) <= UINT_MAX &&      (min_index) <= (index) &&      (2 <= ((N)) <= 100000 &&      \valid(((A)) + (0 .. ((N))-1)) &&      \forall integer i; 0 <= i < ((N)) ==> 1 <= ((A))[i] <= ((N)) &&      \forall integer i, j; 0 <= i < j < ((N)) ==> ((A))[i] != ((A))[j]) &&      ((min) < UINT_MAX ==> (min) >= 1));
        
        if (A[index] == next) {
            next += 1;
        } else {
            min = (min < (unsigned int)next) ? min : (unsigned int)next;
            next = 1;
        }
        index += 1;
    }

    min = (min < (unsigned int)next) ? min : (unsigned int)next;

    if (min == UINT_MAX) {
        return -1;
    } else {
        return (int)min;
    }
}
