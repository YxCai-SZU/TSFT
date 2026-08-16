#include <stdbool.h>

/*@
    requires a > -0x80000000 && a < 0x80000000;
    requires b > -0x80000000 && b < 0x80000000;
    requires c > -0x80000000 && c < 0x80000000;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
*/
bool func(int a, int b, int c) {
    bool greater = false;
    
    //@ assert a > -0x80000000 && a < 0x80000000;
    //@ assert b > -0x80000000 && b < 0x80000000;
    //@ assert c > -0x80000000 && c < 0x80000000;
    
    if (a < b) {
        if (b < c) {
            greater = true;
        } else {
            greater = false;
        }
    } else {
        greater = false;
    }
    
    //@ assert greater == true <==> ((a) < (b) && (b) < (c));
    return greater;
}
