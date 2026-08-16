#include <stdbool.h>
#include <stddef.h>

/*@ requires ((N) > 0 && (N) <= 100000 &&
      \valid((Hs) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> 1 <= (Hs)[i] <= 1000000000);
    ensures 0 <= \result <= N-1;
    assigns \nothing;
*/
unsigned int func(size_t N, const unsigned int *Hs) {
    unsigned int max_count = 0;
    unsigned int tmp_max = 0;
    unsigned int tmp = 0;
    size_t index = 0;
    
    //@ assert ((index) <= (N) - 1 &&       (tmp) <= (index) && (tmp_max) <= (index) && (max_count) <= (index) &&       (((N)) > 0 && ((N)) <= 100000 &&       \valid(((Hs)) + (0 .. ((N))-1)) &&       \forall integer i; 0 <= i < ((N)) ==> 1 <= ((Hs))[i] <= 1000000000));
    
    /*@ loop invariant ((index) <= (N) - 1 &&
      (tmp) <= (index) && (tmp_max) <= (index) && (max_count) <= (index) &&
      (((N)) > 0 && ((N)) <= 100000 &&
      \valid(((Hs)) + (0 .. ((N))-1)) &&
      \forall integer i; 0 <= i < ((N)) ==> 1 <= ((Hs))[i] <= 1000000000));
        loop assigns index, tmp, tmp_max, max_count;
        loop variant N - index;
    */
    while (index < N - 1) {
        //@ assert 0 <= index < N-1;
        
        if (Hs[index] >= Hs[index + 1]) {
            tmp += 1;
        } else {
            if (tmp >= tmp_max) {
                tmp_max = tmp;
            }
            tmp = 0;
        }
        index += 1;
        
        //@ assert ((index) <= (N) - 1 &&       (tmp) <= (index) && (tmp_max) <= (index) && (max_count) <= (index) &&       (((N)) > 0 && ((N)) <= 100000 &&       \valid(((Hs)) + (0 .. ((N))-1)) &&       \forall integer i; 0 <= i < ((N)) ==> 1 <= ((Hs))[i] <= 1000000000));
    }
    
    //@ assert index == N - 1;
    
    if (tmp >= tmp_max) {
        tmp_max = tmp;
    }
    
    max_count = tmp_max;
    
    //@ assert 0 <= max_count <= N-1;
    return max_count;
}
