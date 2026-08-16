#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(v + (0 .. len-1));
    requires ((len) >= 2 &&
        \forall integer i; 0 <= i < (len) ==> (v)[i] >= 1 && (v)[i] <= 16 &&
        \forall integer i; 0 <= i < (len) ==> (v)[i] != i + 1);
    ensures \result == (len >= 2);
*/
bool func(int *v, size_t len) {
    //@ assert len >= 2;
    return len >= 2;
}
