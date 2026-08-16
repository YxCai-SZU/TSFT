#include <stdbool.h>

/*@
    requires (400 <= (X) && (X) < 2000);
    assigns \nothing;
    ensures (1 <= (\result) && (\result) <= 8);
    ensures (((\result) == 8 && 1200 <= (X) && (X) < 2000) ||
        ((\result) == 7 && 900 <= (X) && (X) < 1200) ||
        ((\result) == 6 && 600 <= (X) && (X) < 900) ||
        ((\result) == 5 && 300 <= (X) && (X) < 600) ||
        ((\result) == 4 && 150 <= (X) && (X) < 300) ||
        ((\result) == 3 && 75 <= (X) && (X) < 150) ||
        ((\result) == 2 && 40 <= (X) && (X) < 75) ||
        ((\result) == 1 && 20 <= (X) && (X) < 40) ||
        ((\result) == 0 && (X) < 20));
*/
int func(int X)
{
    int result;
    
    if (X >= 1200 && X < 2000) {
        //@ assert X >= 1200 && X < 2000;
        result = 8;
    } else if (X >= 900 && X < 1200) {
        //@ assert X >= 900 && X < 1200;
        result = 7;
    } else if (X >= 600 && X < 900) {
        //@ assert X >= 600 && X < 900;
        result = 6;
    } else if (X >= 300 && X < 600) {
        //@ assert X >= 300 && X < 600;
        result = 5;
    } else if (X >= 150 && X < 300) {
        //@ assert X >= 150 && X < 300;
        result = 4;
    } else if (X >= 75 && X < 150) {
        //@ assert X >= 75 && X < 150;
        result = 3;
    } else if (X >= 40 && X < 75) {
        //@ assert X >= 40 && X < 75;
        result = 2;
    } else if (X >= 20 && X < 40) {
        //@ assert X >= 20 && X < 40;
        result = 1;
    } else {
        //@ assert X < 20;
        result = 0;
    }
    
    return result;
}
