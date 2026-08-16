#include <stdbool.h>
/*@
    requires 0 <= a <= 100;
    requires 2 <= b <= 1000;
    requires b % 2 == 0;
    ensures ((a) == 0 || (a) == 1 || (a) == 2 || (a) == 3 || (a) == 4 || (a) == 5 || (a) == 6 || (a) == 7 || (a) == 8 || (a) == 9 || (a) == 10 || (a) == 11 || (a) == 12) ==> \result == 0;
    ensures ((a) == 13 || (a) == 14 || (a) == 15 || (a) == 16 || (a) == 17 || (a) == 18 || (a) == 19) ==> \result == 500;
    ensures ((a) >= 20 && (a) <= 39) ==> \result == ((b) / 2);
    ensures ((a) >= 40 && (a) <= 59) ==> \result == ((b) / 2) + ((((b)) / 2) / 2);
    ensures ((a) >= 60) ==> \result == ((b) / 2) + ((((b)) / 2) / 2) + ((((((b))) / 2) / 2) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int result;

    if (a <= 12) {
        result = 0;
        //@ assert ((a) == 0 || (a) == 1 || (a) == 2 || (a) == 3 || (a) == 4 || (a) == 5 || (a) == 6 || (a) == 7 || (a) == 8 || (a) == 9 || (a) == 10 || (a) == 11 || (a) == 12);
    } else if (a <= 19) {
        result = 500;
        //@ assert ((a) == 13 || (a) == 14 || (a) == 15 || (a) == 16 || (a) == 17 || (a) == 18 || (a) == 19);
    } else if (a <= 39) {
        result = b / 2;
        //@ assert ((a) >= 20 && (a) <= 39);
    } else if (a <= 59) {
        result = (b / 2) + (b / 2) / 2;
        //@ assert ((a) >= 40 && (a) <= 59);
    } else {
        result = (b / 2) + (b / 2) / 2 + (b / 2) / 2 / 2;
        //@ assert ((a) >= 60);
    }

    return result;
}
