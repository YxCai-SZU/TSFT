#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(Hs + (0 .. N-1));
    requires ((N) > 0 && (N) <= 100000 &&
      \forall integer i; 0 <= i < (N) ==> 1 <= (Hs)[i] && (Hs)[i] <= 1000000000);
    assigns \nothing;
    ensures \result <= N;
*/
unsigned int func(size_t N, const unsigned int *Hs) {
    unsigned int max = 0;
    unsigned int count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= N;
        loop invariant count <= index;
        loop invariant ((N) > 0 && (N) <= 100000 &&
      \forall integer i; 0 <= i < (N) ==> 1 <= (Hs)[i] && (Hs)[i] <= 1000000000);
        loop assigns max, count, index;
        loop variant N - index;
    */
    while (index < N) {
        unsigned int H = Hs[index];
        if (max <= H) {
            max = H;
            count++;
        }
        index++;
        //@ assert count <= index;
    }
    return count;
}
