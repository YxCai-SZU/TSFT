#include <stdbool.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3142 / 1000;
*/
int func(int r) {
    int pi_approx;
    int scaled_value;
    int scaled_result;
    int divisor;
    int result;
    int temp;
    
    pi_approx = 3142;
    scaled_value = r * pi_approx;
    scaled_result = 2 * scaled_value;
    divisor = 1000;
    result = 0;
    temp = scaled_result;
    
    /*@
        loop invariant (1 <= (r) <= 100 &&
        (pi_approx) == 3142 &&
        (scaled_value) == (r) * (pi_approx) &&
        (scaled_result) == 2 * (scaled_value) &&
        (divisor) == 1000 &&
        (result) * (divisor) + (temp) == (scaled_result) &&
        0 <= (result) * (divisor) + (temp) <= 2 * 100 * 3142 &&
        0 <= (result) * 1000 <= 2 * 100 * 3142 &&
        (temp) >= 0);
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        result += 1;
    }
    
    //@ assert result * 1000 + temp == scaled_result;
    return result;
}

int main() {
    return 0;
}
