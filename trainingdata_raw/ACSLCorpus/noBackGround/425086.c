#include <stdbool.h>

/*@
    requires \valid(v+(0..len-1));
    requires (\forall integer i; 0 <= i < (len) ==> ((v)[i] > 0 && (v)[i] <= (upper) && (v)[i] >= (lower)));
    requires (\forall integer i; 0 <= i < (len) ==> ((v)[i] % 2 == 0 && (v)[i] <= (upper) && (v)[i] >= (lower)));
    ensures \result == true;
*/
bool func(int *v, int len, int lower, int upper) {
    //@ assert (\forall integer i; 0 <= i < (len) ==> ((v)[i] > 0 && (v)[i] <= (upper) && (v)[i] >= (lower)));
    //@ assert (\forall integer i; 0 <= i < (len) ==> ((v)[i] % 2 == 0 && (v)[i] <= (upper) && (v)[i] >= (lower)));
    return true;
}
