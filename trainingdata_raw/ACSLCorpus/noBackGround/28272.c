#include <stdint.h>

/*@
    requires 400 <= x && x <= 1999;
    ensures \result == ((x) <= 599 ? 8 :
        (x) <= 799 ? 7 :
        (x) <= 999 ? 6 :
        (x) <= 1199 ? 5 :
        (x) <= 1399 ? 4 :
        (x) <= 1599 ? 3 :
        (x) <= 1799 ? 2 :
        (x) <= 1999 ? 1 : -1);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result;
    
    if (x <= 599) {
        //@ assert x <= 599;
        result = 8;
    } else if (x <= 799) {
        //@ assert 600 <= x && x <= 799;
        result = 7;
    } else if (x <= 999) {
        //@ assert 800 <= x && x <= 999;
        result = 6;
    } else if (x <= 1199) {
        //@ assert 1000 <= x && x <= 1199;
        result = 5;
    } else if (x <= 1399) {
        //@ assert 1200 <= x && x <= 1399;
        result = 4;
    } else if (x <= 1599) {
        //@ assert 1400 <= x && x <= 1599;
        result = 3;
    } else if (x <= 1799) {
        //@ assert 1600 <= x && x <= 1799;
        result = 2;
    } else if (x <= 1999) {
        //@ assert 1800 <= x && x <= 1999;
        result = 1;
    } else {
        //@ assert x < 400 || x > 1999;
        result = -1;
    }
    
    return result;
}
