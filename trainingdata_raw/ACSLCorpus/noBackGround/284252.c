#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= h <= 100;
    requires ((h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
*/
int func(int a, int b, int h) {
    int sum;
    int product;
    int half;
    int result;
    int temp;

    sum = a + b;
    //@ assert 1 <= sum <= 200;
    //@ assert 1 <= sum * h <= 200 * 100;
    product = sum * h;
    half = 2;
    result = 0;
    temp = product;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= h <= 100;
        loop invariant ((h) % 2 == 0);
        loop invariant temp >= 0;
        loop invariant temp == product - 2 * result;
        loop invariant result >= 0;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= half) {
        temp -= half;
        result += 1;
    }

    return result;
}
