#include <stdbool.h>

/*@ requires \valid(v+(0..3));
    requires ((4) == 4);
    requires (\forall integer i; 0 <= i < (4) ==> (-100 <= ((v)[i]) <= 100));
    ensures (((v)[(0)]) == ((v)[(2)]) && 
             ((v)[(1)]) == ((v)[(3)]) && \result == 0) ||
            (((v)[(0)]) != ((v)[(2)]) || 
             ((v)[(1)]) != ((v)[(3)]) && \result == 1);
*/
int func(int *v) {
    int result;
    
    //@ assert ((4) == 4);
    
    if (v[0] == v[2] && v[1] == v[3]) {
        result = 0;
    } else {
        result = 1;
    }
    
    return result;
}
