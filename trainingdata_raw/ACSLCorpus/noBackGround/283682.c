#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int sum;
    unsigned int avg;
    bool is_odd;
    unsigned int temp_sum;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    sum = a + b;
    avg = 0;
    is_odd = false;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant avg == (sum - temp_sum) / 2;
        loop invariant temp_sum == sum - avg * 2;
        loop invariant sum == a + b;
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
        loop assigns temp_sum, avg;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        avg += 1;
    }

    if (temp_sum == 1) {
        is_odd = true;
    }

    if (is_odd) {
        avg += 1;
    }

    //@ assert avg == (((a) + (b) + 1) / 2);
    return avg;
}
