#include <limits.h>

/*@
    requires (INT_MIN <= (x) <= INT_MAX);
    ensures \result == ((x) < 1 ? 0 :
        (x) < 3 ? 1 :
        (x) < 6 ? 2 :
        (x) < 10 ? 3 :
        (x) < 15 ? 4 :
        (x) < 21 ? 5 :
        (x) < 28 ? 6 :
        (x) < 36 ? 7 :
        (x) < 45 ? 8 :
        (x) < 55 ? 9 :
        10);
    ensures (x < 1 ==> \result == 0);
    ensures (x >= 1 && x < 3 ==> \result == 1);
    ensures (x >= 3 && x < 6 ==> \result == 2);
    ensures (x >= 6 && x < 10 ==> \result == 3);
    ensures (x >= 10 && x < 15 ==> \result == 4);
    ensures (x >= 15 && x < 21 ==> \result == 5);
    ensures (x >= 21 && x < 28 ==> \result == 6);
    ensures (x >= 28 && x < 36 ==> \result == 7);
    ensures (x >= 36 && x < 45 ==> \result == 8);
    ensures (x >= 45 && x < 55 ==> \result == 9);
    ensures (x >= 55 && x < 1000000 ==> \result == 10);
*/
int func(int x)
{
    int result;

    if (x < 1) {
        //@ assert x < 1;
        result = 0;
    } else if (x < 3) {
        //@ assert x >= 1 && x < 3;
        result = 1;
    } else if (x < 6) {
        //@ assert x >= 3 && x < 6;
        result = 2;
    } else if (x < 10) {
        //@ assert x >= 6 && x < 10;
        result = 3;
    } else if (x < 15) {
        //@ assert x >= 10 && x < 15;
        result = 4;
    } else if (x < 21) {
        //@ assert x >= 15 && x < 21;
        result = 5;
    } else if (x < 28) {
        //@ assert x >= 21 && x < 28;
        result = 6;
    } else if (x < 36) {
        //@ assert x >= 28 && x < 36;
        result = 7;
    } else if (x < 45) {
        //@ assert x >= 36 && x < 45;
        result = 8;
    } else if (x < 55) {
        //@ assert x >= 45 && x < 55;
        result = 9;
    } else {
        result = 10;
    }

    return result;
}
