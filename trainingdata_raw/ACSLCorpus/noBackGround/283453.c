#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(numbers + (0..len-1));
    requires len < 0x80000000;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> ((((numbers[i]) & 1) != 0) ==> \result > 0);
*/
int odd_count(const int *numbers, size_t len) {
    int count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> ((((numbers[j]) & 1) != 0) ==> count > 0);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert count <= i;
        if ((numbers[i] & 1) != 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}
