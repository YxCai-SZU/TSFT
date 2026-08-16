#include <stdint.h>
#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] && (v)[0] <= 100 &&
        1 <= (v)[1] && (v)[1] <= 20 &&
        1 <= (v)[2] && (v)[2] <= 2000);
    ensures \result >= 0;
    ensures \result == v[2] || \result == ((v[0]) * (v[1]));
    assigns \nothing;
*/
int64_t func(int64_t* v) {
    int64_t res;
    
    //@ assert 1 <= v[0] && v[0] <= 100 && 1 <= v[1] && v[1] <= 20;
    //@ assert ((v[0]) * (v[1])) <= 2000;
    
    if (v[0] * v[1] > v[2]) {
        res = v[2];
    } else {
        res = v[0] * v[1];
    }
    
    return res;
}
