#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0..len-1));
    requires len <= 0x80000000;
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures \forall size_t i; 0 <= i < len && numbers[i] == 0 ==> \result > 0;
*/
size_t count_zeros(const int *numbers, size_t len) {
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall size_t j; 0 <= j < i && numbers[j] == 0 ==> count > 0;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (numbers[i] == 0) {
            //@ assert numbers[i] == 0;
            count++;
            //@ assert count > 0;
        }
        i++;
    }
    return count;
}
