#include <stdbool.h>

/*@
    requires (\valid((input) + (0..5)) &&
        (\forall integer i; 0 <= i < 6 ==> 0 <= (input)[i] && (input)[i] <= 123) &&
        (input)[0] < (input)[1] && (input)[1] < (input)[2] && 
        (input)[2] < (input)[3] && (input)[3] < (input)[4]);
    ensures \result == (input[4] - input[0] <= input[5]);
    assigns \nothing;
*/
bool func(int *input) {
    int a, b, c, d, e, k;
    
    a = input[0];
    b = input[1];
    c = input[2];
    d = input[3];
    e = input[4];
    k = input[5];
    
    //@ assert e >= a;
    //@ assert e - a <= 123;
    
    if (e - a <= k) {
        return true;
    } else {
        return false;
    }
}
