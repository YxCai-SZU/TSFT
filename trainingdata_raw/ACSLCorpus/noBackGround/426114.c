#include <stdbool.h>

/*@ requires 0 <= n <= 4294967295;
    ensures \result == true ==> n % 2 == 0;
    ensures \result == false ==> n % 2 != 0;
    assigns \nothing;
*/
bool is_even_func(unsigned int n) {
    //@ assert n % 2 == 0 || n % 2 != 0;
    return n % 2 == 0;
}

/*@ requires 0 <= n <= 4294967295;
    ensures \result == true ==> n % 2 != 0;
    ensures \result == false ==> n % 2 == 0;
    assigns \nothing;
*/
bool is_odd_func(unsigned int n) {
    //@ assert n % 2 == 0 || n % 2 != 0;
    return n % 2 != 0;
}

/*@ requires 1 <= r <= 100;
    ensures \result == r * 2 * 3;
    assigns \nothing;
*/
int func(int r) {
    int pi = 3;
    int res = r * 2 * pi;
    //@ assert res == r * 2 * 3;
    return res;
}
