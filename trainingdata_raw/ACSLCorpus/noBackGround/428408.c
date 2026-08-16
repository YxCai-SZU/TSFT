#include <stdbool.h>

/*@
    requires (-1000 <= (a) && (a) <= 1000) && (-1000 <= (b) && (b) <= 1000);
    ensures \result == a + b;
    assigns \nothing;
*/
int sum(int a, int b) {
    //@ assert (-1000 <= (a) && (a) <= 1000);
    //@ assert (-1000 <= (b) && (b) <= 1000);
    //@ assert -2000 <= a + b && a + b <= 2000;
    return a + b;
}
