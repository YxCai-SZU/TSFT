#include <stdbool.h>

/*@
    predicate is_even_condition(integer n, bool ret) =
        ret == true ==> n % 2 == 0 &&
        ret == false ==> n % 2 != 0;
*/

/*@
    requires n >= 0;
    ensures \result == true ==> n % 2 == 0;
    ensures \result == false ==> n % 2 != 0;
*/
bool is_even(int n) {
    bool ret = false;
    int abs_n;
    
    //@ assert n >= 0;
    if (n < 0) {
        abs_n = -n;
    } else {
        abs_n = n;
    }
    
    //@ assert abs_n >= 0;
    //@ assert abs_n % 2 == n % 2;
    
    /*@
        loop invariant abs_n >= 0;
        loop invariant abs_n % 2 == n % 2;
        loop assigns abs_n;
        loop variant abs_n;
    */
    while (abs_n >= 2) {
        //@ assert abs_n >= 2;
        abs_n -= 2;
        //@ assert abs_n >= 0;
        //@ assert abs_n % 2 == n % 2;
    }
    
    //@ assert abs_n >= 0 && abs_n < 2;
    if (abs_n == 0) {
        ret = true;
        //@ assert n % 2 == 0;
    } else {
        ret = false;
        //@ assert n % 2 != 0;
    }
    
    //@ assert is_even_condition(n, ret);
    return ret;
}

int main() {
    return 0;
}
