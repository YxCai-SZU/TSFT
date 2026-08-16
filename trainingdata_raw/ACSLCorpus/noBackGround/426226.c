#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * (31415)* (r)) / 10000);
*/
int func(int r) {
    // Variable declarations at scope top
    int pi_approx;
    int circumference;
    int result;
    int temp;
    
    pi_approx = 31415;
    circumference = 2 * pi_approx * r;
    result = 0;
    temp = circumference;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant 0 <= temp && temp <= 2 * (31415)* r;
        loop invariant result * 10000 + temp == circumference;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= 10000) {
        //@ assert temp >= 10000;
        result += 1;
        temp -= 10000;
    }
    
    //@ assert result == ((2 * (31415)* (r)) / 10000);
    return result;
}
