#include <stdbool.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * 31415 * r) / 10000;
    assigns \nothing;
*/
int func(int r) {
    int pi_approx = 31415;
    int scale = 10000;
    int circumference = 0;
    int temp = 2 * pi_approx * r;
    int count = 0;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert pi_approx == (31415);
    //@ assert scale == (10000);
    //@ assert temp == 2 * (31415)* r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 31415;
        loop invariant scale == 10000;
        loop invariant temp >= 0;
        loop invariant temp == 2 * pi_approx * r - count * scale;
        loop invariant count >= 0;
        loop invariant circumference == count;
        loop assigns circumference, temp, count;
        loop variant temp;
    */
    while (temp >= scale) {
        circumference += 1;
        temp -= scale;
        count += 1;
        
        //@ assert temp == 2 * pi_approx * r - count * scale;
    }
    
    //@ assert temp < scale;
    //@ assert circumference * scale + temp == 2 * pi_approx * r;
    //@ assert circumference == (2 * pi_approx * r) / scale;
    
    return circumference;
}

int main() {
    return 0;
}
