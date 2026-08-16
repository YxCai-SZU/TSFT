#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100);
    requires (1 <= (x) <= 100000);
    ensures \result == (k * (500)>= x);
*/
bool func(int k, int x) {
    int en = 500;
    //@ assert en == (500);
    return k * en >= x;
}

/*@
    requires (1 <= (k) <= 100);
    requires (1 <= (x) <= 100000);
    ensures \result == (k * (500)>= x);
*/
bool func2(int k, int x) {
    int en = 500;
    //@ assert k >= 1 && k <= 100;
    //@ assert x >= 1 && x <= 100000;
    //@ assert en >= 500;
    //@ assert k * en <= 100000;
    return k * en >= x;
}

/*@
    requires (1 <= (k) <= 100);
    requires (1 <= (x) <= 100000);
    ensures \result == (k * (500)>= x);
*/
bool func3(int k, int x) {
    int en = 500;
    //@ assert k * en <= 100000;
    return k * en >= x;
}
