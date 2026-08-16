#include <stdbool.h>

/*@
    requires ((x) < 10);
    ensures \result == true;
*/
bool function_less_than_ten(unsigned int x) {
    //@ assert x < 10;
    return true;
}

/*@
    requires ((x) > 10);
    ensures \result == true;
*/
bool function_greater_than_ten(unsigned int x) {
    //@ assert x > 10;
    return true;
}

/*@
    requires ((x) > 10 && (x) < 50);
    ensures \result == true;
*/
bool function_between_ten_and_fifty(unsigned int x) {
    //@ assert x > 10 && x < 50;
    return true;
}

/*@
    requires ((x) > 50);
    ensures \result == true;
*/
bool function_greater_than_fifty(unsigned int x) {
    //@ assert x > 50;
    return true;
}

/*@
    requires ((x) > 10 && (x) < 100);
    ensures \result == true;
*/
bool function_between_ten_and_hundred(unsigned int x) {
    //@ assert x > 10 && x < 100;
    return true;
}

/*@
    requires ((x) > 100);
    ensures \result == true;
*/
bool function_greater_than_hundred(unsigned int x) {
    //@ assert x > 100;
    return true;
}

/*@
    requires ((x) % 2 == 0);
    ensures \result == true;
*/
bool function_even(unsigned int x) {
    //@ assert x % 2 == 0;
    return true;
}

/*@
    requires ((x) % 2 != 0);
    ensures \result == true;
*/
bool function_odd(unsigned int x) {
    //@ assert x % 2 != 0;
    return true;
}

/*@
    requires ((x) == 10);
    ensures \result == true;
*/
bool function_is_ten(unsigned int x) {
    //@ assert x == 10;
    return true;
}

/*@
    requires ((x) == 50);
    ensures \result == true;
*/
bool function_is_fifty(unsigned int x) {
    //@ assert x == 50;
    return true;
}

/*@
    requires ((x) == 100);
    ensures \result == true;
*/
bool function_is_hundred(unsigned int x) {
    //@ assert x == 100;
    return true;
}

/*@
    requires ((x) > 10 && (x) < 50);
    ensures \result == true;
*/
bool function_is_greater_than_ten_less_than_fifty(unsigned int x) {
    //@ assert x > 10 && x < 50;
    return true;
}

/*@
    requires ((x) > 50 && (x) < 100);
    ensures \result == true;
*/
bool function_is_greater_than_fifty_less_than_hundred(unsigned int x) {
    //@ assert x > 50 && x < 100;
    return true;
}
