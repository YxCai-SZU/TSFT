#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/*@
    requires \valid_read(test_tup1 + (0..len-1));
    requires \valid_read(test_tup2 + (0..len-1));
    requires len >= 0;
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < len ==> test_tup1[i] == test_tup2[i]);
    ensures \result >= 0 ==> (\result < len && test_tup1[\result] != test_tup2[\result]);
*/
int find_difference(const unsigned int *test_tup1, const unsigned int *test_tup2, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (test_tup1)[j] == (test_tup2)[j]);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (test_tup1[i] != test_tup2[i]) {
            //@ assert test_tup1[i] != test_tup2[i];
            return i;
        }
        //@ assert test_tup1[i] == test_tup2[i];
        i = i + 1;
    }
    return -1;
}
