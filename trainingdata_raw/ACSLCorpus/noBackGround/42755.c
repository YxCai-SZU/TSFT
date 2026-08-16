#include <stdbool.h>

/*@
requires ((x) >= 0);
ensures \result <= x + 5;
*/
int transitivity_example(int x) {
    //@ assert x >= 0;
    return x;
}

/*@
requires ((x) >= 0) && (0 <= (x) && (x) <= 100);
ensures \result <= 100;
*/
int inequality_preservation(int x) {
    //@ assert x >= 0;
    return x;
}

/*@
requires ((x) >= 0) && (0 <= (x) && (x) <= 100);
ensures \result <= 200;
*/
int monotonicity(int x) {
    //@ assert x <= 100;
    return x;
}

/*@
requires ((x) >= 0) && (0 <= (x) && (x) <= 100);
ensures \result / 2 <= 50;
*/
int decreasing_example(int x) {
    //@ assert x <= 100;
    return x;
}

/*@
requires ((x) >= 0) && (0 <= (x) && (x) <= 100);
ensures \result <= 101;
*/
int ceiling_example(int x) {
    //@ assert x <= 100;
    return x;
}

/*@
requires ((x) >= 0) && (0 <= (x) && (x) <= 100);
ensures \result <= 1000;
*/
int upper_bound_example(int x) {
    //@ assert x <= 100;
    return x;
}

/*@
requires ((x) >= 0) && (0 <= (x) && (x) <= 100);
ensures 0 <= \result;
*/
int lower_bound_example(int x) {
    //@ assert 0 <= x;
    return x;
}

int main() {
    return 0;
}
