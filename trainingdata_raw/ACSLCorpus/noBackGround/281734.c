#include <stdbool.h>

/*@
    requires \valid_read(v + (0 .. n-1));
    requires n >= 2;
    ensures \result == (v[n-1] > v[0]);
*/
bool func(int *v, int n) {
    //@ assert n >= 2;
    return v[n - 1] > v[0];
}
