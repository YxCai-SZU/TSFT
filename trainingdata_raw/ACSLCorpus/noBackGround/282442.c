#include <stdbool.h>

/*@
    requires 1 <= x <= 10000;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (x % 3 == 0 || x % 5 == 0);
    ensures \result == 0 ==> (x % 3 != 0 && x % 5 != 0);
*/
int func(int x) {
    bool is_divisible_by_3 = false;
    bool is_divisible_by_5 = false;
    int temp;
    
    // Check divisibility by 3
    temp = x;
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant temp >= 0;
        loop invariant temp <= x;
        loop invariant temp % 3 == x % 3;
        loop assigns temp;
    */
    while (temp >= 3) {
        temp -= 3;
    }
    if (temp == 0) {
        is_divisible_by_3 = true;
    }
    
    // Check divisibility by 5
    temp = x;
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant temp >= 0;
        loop invariant temp <= x;
        loop invariant temp % 5 == x % 5;
        loop assigns temp;
    */
    while (temp >= 5) {
        temp -= 5;
    }
    if (temp == 0) {
        is_divisible_by_5 = true;
    }
    
    if (is_divisible_by_3 || is_divisible_by_5) {
        //@ assert x % 3 == 0 || x % 5 == 0;
        return 1;
    } else {
        //@ assert x % 3 != 0 && x % 5 != 0;
        return 0;
    }
}
