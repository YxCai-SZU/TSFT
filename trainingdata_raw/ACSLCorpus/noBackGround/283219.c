#include <stdbool.h>

/*@
    requires ((len) >= 4 &&
        1 <= (x)[0] <= 10000 &&
        1 <= (x)[1] <= 10000 &&
        1 <= (x)[2] <= 10000 &&
        1 <= (x)[3] <= 10000);
    ensures \result == ((x[0]) * (x[1])) ||
            \result == ((x[2]) * (x[3])) ||
            \result == ((x[0]) * (x[2])) ||
            \result == ((x[1]) * (x[3]));
*/
int func(int* x, int len) {
    int tmp[4];
    int max_value;
    int i;
    
    //@ assert ((len) >= 4 &&         1 <= (x)[0] <= 10000 &&         1 <= (x)[1] <= 10000 &&         1 <= (x)[2] <= 10000 &&         1 <= (x)[3] <= 10000);
    
    //@ assert 1 <= x[0] * x[1] <= 100000000;
    tmp[0] = x[0] * x[1];
    
    //@ assert 1 <= x[2] * x[3] <= 100000000;
    tmp[1] = x[2] * x[3];
    
    //@ assert 1 <= x[0] * x[2] <= 100000000;
    tmp[2] = x[0] * x[2];
    
    //@ assert 1 <= x[1] * x[3] <= 100000000;
    tmp[3] = x[1] * x[3];
    
    max_value = tmp[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == tmp[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= tmp[j];
        loop invariant 1 <= max_value <= 100000000;
        loop assigns i, max_value;
    */
    while (i < 4) {
        if (tmp[i] > max_value) {
            max_value = tmp[i];
        }
        i++;
    }
    
    return max_value;
}
