#include <stdbool.h>

/*@ requires \valid(v+(0..2));
    requires ((3) >= 3 &&
    1 <= (v)[0] && (v)[0] <= 100 &&
    1 <= (v)[1] && (v)[1] <= 20 &&
    1 <= (v)[2] && (v)[2] <= 2000);
    ensures \result <= v[2];
    ensures \result >= 0;
    ensures \result == v[1] * v[0] || \result == v[2];
*/
int func(int *v) {
    int x;
    
    //@ assert 1 <= v[1] && v[1] <= 20;
    //@ assert 1 <= v[0] && v[0] <= 100;
    //@ assert v[1] * v[0] <= 2000;
    
    x = v[1] * v[0];
    
    if (x < v[2]) {
        return x;
    } else {
        return v[2];
    }
}
