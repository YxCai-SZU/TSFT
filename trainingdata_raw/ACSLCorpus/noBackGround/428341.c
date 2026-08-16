#include <stdbool.h>
#include <stdint.h>

/*@
   requires \valid(seq + (0..len-1));
   requires 0 <= len < 0x80000000;
   assigns \nothing;
   ensures 0 <= \result <= len;
*/
uint32_t count_unique_subsequences(uint32_t *seq, uint32_t len) {
    uint32_t count = 0;
    uint32_t i = 0;
    uint32_t j = 0;
    bool is_unique = true;

    /*@
       loop invariant 0 <= i <= len;
       loop invariant 0 <= count <= i;
       loop assigns i, count, j, is_unique;
       loop variant len - i;
    */
    while (i < len) {
        is_unique = true;
        j = 0;

        /*@
           loop invariant 0 <= j <= i;
           loop invariant is_unique ==> (\forall integer k; 0 <= k < (j) ==> (seq)[(i)] != (seq)[k]);
           loop assigns j, is_unique;
           loop variant i - j;
        */
        while (j < i) {
            //@ assert 0 <= j < i;
            if (seq[i] == seq[j]) {
                is_unique = false;
                break;
            }
            j++;
        }

        if (is_unique) {
            //@ assert count < 0xFFFFFFFF;
            count++;
        }
        i++;
    }

    //@ assert 0 <= count <= len;
    return count;
}
