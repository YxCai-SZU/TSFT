#include <stdbool.h>

/*@
    requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
        1 <= (v)[0] <= 9 &&
        1 <= (v)[1] <= 9 &&
        1 <= (v)[2] <= 9);
    ensures \result == (((v[0]) * 100 + (v[1]) * 10 + (v[2])) % 4 == 0);
*/
bool func(int *v) {
    int sum;
    int temp_sum;
    
    //@ assert v[0] >= 1 && v[0] <= 9;
    //@ assert v[1] >= 1 && v[1] <= 9;
    //@ assert v[2] >= 1 && v[2] <= 9;
    
    sum = v[0] * 100 + v[1] * 10 + v[2];
    temp_sum = sum;
    
    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 4 == sum % 4;
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 4) {
        temp_sum -= 4;
    }
    
    //@ assert temp_sum == sum % 4;
    
    return temp_sum == 0;
}
