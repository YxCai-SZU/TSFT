#include <stdbool.h>

/*@ requires ((4) == 4 &&
    \forall integer i; 0 <= i < (4) ==> -100 <= (v)[i] <= 100);
    assigns \nothing;
    ensures (v[0] == v[2] && \result == v[3] - v[1]) ||
            (v[0] != v[2] && \result == v[2] - v[1]);
*/
int func(int *v) {
    int a;
    int b;
    int c;
    int k;
    int result;
    
    a = v[0];
    b = v[1];
    c = v[2];
    k = v[3];
    result = 0;
    
    //@ assert ((4) == 4 &&     \forall integer i; 0 <= i < (4) ==> -100 <= (v)[i] <= 100);
    
    if (a == c) {
        result = k - b;
        //@ assert a == c && result == v[3] - v[1];
    } else {
        result = c - b;
        //@ assert a != c && result == v[2] - v[1];
    }
    
    //@ assert (v[0] == v[2] && result == v[3] - v[1]) || (v[0] != v[2] && result == v[2] - v[1]);
    return result;
}
