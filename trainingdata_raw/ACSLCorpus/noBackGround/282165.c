#include <stdbool.h>
/*@
    requires \valid(v) && (1 <= (v)[0] <= 100 &&
        0 <= (v)[1] <= (v)[0]);
    assigns v[0], v[1];
    ensures \result == (v[0] == v[1]);
*/
bool func(int *v) {
    //@ ghost int old_v0 = v[0];
    //@ ghost int old_v1 = v[1];
    int i = 0;
    /*@
        loop invariant 0 <= i <= old_v0;
        loop invariant v[0] == old_v0;
        loop invariant v[1] == old_v1;
        loop invariant (1 <= (v)[0] <= 100 &&
        0 <= (v)[1] <= (v)[0]);
        loop assigns i, v[0], v[1];
    */
    while (i < v[0]) {
        i = i + 1;
    }
    //@ assert i == old_v0;
    bool result = (v[0] == v[1]);
    //@ assert result == (old_v0 == old_v1);
    return result;
}
