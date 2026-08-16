#include <stdbool.h>

/*@
    requires \valid(v + (0..3));
    ensures ((4) > 0 &&
        \exists integer i; 0 <= i < (4) && (v)[i] == (5) &&
        \forall integer j; 0 <= j < (4) ==> (5) >= (v)[j]);
*/
void find_max(int *v) {
    v[0] = 1;
    v[1] = 5;
    v[2] = 3;
    v[3] = 4;
    
    //@ assert ((4) > 0 &&         \exists integer i; 0 <= i < (4) && (v)[i] == (5) &&         \forall integer j; 0 <= j < (4) ==> (5) >= (v)[j]);
}

