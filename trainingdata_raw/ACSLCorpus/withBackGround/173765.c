#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
    predicate is_even(integer v) = v % 2 == 0;
    logic integer trapezoid_area(integer a, integer b, integer h) = (a + b) * h / 2;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(h);
    requires is_even(h);
    ensures \result == trapezoid_area(a, b, h);
*/
int func(int a, int b, int h) {
    int sum;
    int product;
    int result;
    int count;
    int temp;

    sum = a + b;
    //@ assert 1 <= sum <= 200;
    product = sum * h;
    //@ assert 1 <= product <= 20000;
    
    result = 0;
    count = 0;
    temp = product;

    /*@
        loop invariant 0 <= temp <= product;
        loop invariant count == (product - temp) / 2;
        loop invariant temp + 2 * count == product;
        loop invariant product == sum * h;
        loop invariant valid_range(a) && valid_range(b) && valid_range(h);
        loop invariant is_even(h);
        loop invariant sum == a + b;
        loop assigns temp, count;
    */
    while (temp >= 2) {
        temp -= 2;
        count += 1;
    }

    result = count;
    //@ assert result == trapezoid_area(a, b, h);
    return result;
}

int main() {
    return 0;
}
