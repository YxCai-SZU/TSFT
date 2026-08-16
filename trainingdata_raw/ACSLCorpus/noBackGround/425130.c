#include <stdbool.h>

/*@
    requires \valid(v+(0..5));
    requires 0 <= v[0] < 24;
    requires 0 <= v[1] < 60;
    requires 0 <= v[2] < 24;
    requires 0 <= v[3] < 60;
    requires 0 <= v[4] < 24;
    requires 0 <= v[5] < 60;
    ensures \result == (
        (v[0] * 60 + v[1] < v[2] * 60 + v[3] && 
         v[2] * 60 + v[3] < v[4] * 60 + v[5]) ||
        (v[0] * 60 + v[1] < v[4] * 60 + v[5] && 
         v[4] * 60 + v[5] < v[2] * 60 + v[3])
    );
*/
bool func(int v[6]) {
    int s;
    int t;
    int u;
    bool result;

    //@ assert 0 <= v[0] * 60 + v[1] < 24 * 60 + 60;
    //@ assert 0 <= v[2] * 60 + v[3] < 24 * 60 + 60;
    //@ assert 0 <= v[4] * 60 + v[5] < 24 * 60 + 60;

    s = v[0] * 60 + v[1];
    t = v[2] * 60 + v[3];
    u = v[4] * 60 + v[5];

    result = (s < t && t < u) || (s < u && u < t);
    return result;
}
