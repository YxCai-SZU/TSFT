#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * 31415 * (r)) / 10000);
    assigns \nothing;
*/
int func(int r) {
    int circumference = 0;
    int temp = 2 * 31415 * r;
    int divisor = 10000;
    
    //@ assert temp >= 0 && temp <= 2 * 31415 * 100;
    
    /*@
        loop invariant circumference * divisor + temp == 2 * 31415 * r;
        loop invariant temp >= 0;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference * divisor <= 2 * 31415 * r;
    //@ assert circumference * divisor + temp == 2 * 31415 * r;
    //@ assert temp < divisor;
    
    return circumference;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
