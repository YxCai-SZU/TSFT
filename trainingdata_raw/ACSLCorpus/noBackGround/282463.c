#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 3 &&
        \forall integer i; 0 <= i < (len) ==> 
            (1 <= ((v)[i]) <= 1000000000));
    ensures \result == true <==> (((v[0]) < (v[1]) && (v[1]) < (v[2])) || ((v[0]) > (v[1]) && (v[1]) > (v[2])));
    assigns \nothing;
*/
bool func(int *v, int len) {
    int a;
    int b;
    int c;
    bool result;

    //@ assert len >= 3;

    a = v[0];
    b = v[1];
    c = v[2];

    if (a < b && b < c) {
        //@ assert (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        result = true;
    } else if (a > b && b > c) {
        //@ assert (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
        result = true;
    } else {
        result = false;
    }

    return result;
}
