#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a % 2 == 0 || b % 2 == 0);
*/
bool func(unsigned int a, unsigned int b) {
    bool result;
    //@ assert ((((a)) % 2 == 0) || (((b)) % 2 == 0)) <==> (a % 2 == 0 || b % 2 == 0);
    if (a % 2 == 0 || b % 2 == 0) {
        result = true;
    } else {
        result = false;
    }
    //@ assert result == (a % 2 == 0 || b % 2 == 0);
    return result;
}

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a % 2 == 0 || b % 2 == 0);
*/
bool check_either_even(unsigned int a, unsigned int b) {
    bool result;
    //@ assert ((((a)) % 2 == 0) || (((b)) % 2 == 0)) <==> (a % 2 == 0 || b % 2 == 0);
    result = (a % 2 == 0 || b % 2 == 0);
    //@ assert result == (a % 2 == 0 || b % 2 == 0);
    return result;
}
