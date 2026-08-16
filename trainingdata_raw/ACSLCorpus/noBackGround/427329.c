#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    requires \valid(v + (0..len-1));
    requires (\forall integer k; 0 <= k < (len) ==> 0 <= (v)[k] < 0x100000000);
    assigns \nothing;
    ensures \result == SIZE_MAX ==> (\forall integer i; 0 <= i < (len) ==> ((v)[i] % 2 != 0) || ((v)[i] < 10));
    ensures \result != SIZE_MAX ==> (0 <= (\result) < (len) &&
        (v)[(\result)] % 2 == 0 &&
        (v)[(\result)] >= 10 &&
        \forall integer i; 0 <= i < (\result) ==> ((v)[i] % 2 != 0) || ((v)[i] < 10));
*/
size_t func(const int64_t *v, size_t len) {
    size_t index;
    index = 0;

    /*@
        loop invariant 0 <= index <= len;
        loop invariant \forall integer i; 0 <= i < index ==> (v[i] % 2 != 0) || (v[i] < 10);
        loop invariant (\forall integer k; 0 <= k < (len) ==> 0 <= (v)[k] < 0x100000000);
        loop assigns index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert 0 <= index < len;
        if (v[index] >= 10 && v[index] % 2 == 0) {
            //@ assert (0 <= (index) < (len) &&         (v)[(index)] % 2 == 0 &&         (v)[(index)] >= 10 &&         \forall integer i; 0 <= i < (index) ==> ((v)[i] % 2 != 0) || ((v)[i] < 10));
            return index;
        }
        //@ assert (v[index] % 2 != 0) || (v[index] < 10);
        index = index + 1;
    }
    //@ assert (\forall integer i; 0 <= i < (len) ==> ((v)[i] % 2 != 0) || ((v)[i] < 10));
    return SIZE_MAX;
}
