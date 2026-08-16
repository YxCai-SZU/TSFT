#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (((v)[i]) == 0 || ((v)[i]) == 1));
    ensures \result == ((((v)[0] == 0 || (v)[1] == 0 || (v)[2] == 0) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    int sum;
    int product;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    //@ assert ((a) == 0 || (a) == 1);
    //@ assert ((b) == 0 || (b) == 1);
    //@ assert ((c) == 0 || (c) == 1);
    
    sum = a + b + c;
    
    if (sum == 0) {
        return true;
    } else {
        //@ assert a * b <= 1;
        product = a * b * c;
        if (product == 0) {
            return true;
        } else {
            return false;
        }
    }
}
