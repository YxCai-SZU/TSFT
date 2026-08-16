#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == a * b;
*/
int product_parallelogram_func(int a, int b) {
    //@ assert (0 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) <= 100);
    int result;
    result = a * b;
    //@ assert result == a * b;
    return result;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == a + b;
*/
int sum_parallelogram_func(int a, int b) {
    //@ assert (0 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) <= 100);
    int result;
    result = a + b;
    //@ assert result == a + b;
    return result;
}

/*@
    requires 0 <= a <= 100;
    ensures \result == a * a;
*/
int product_square_func(int a) {
    //@ assert (0 <= (a) && (a) <= 100);
    int result;
    result = a * a;
    //@ assert result == a * a;
    return result;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == a * a - b * b;
*/
int difference_square_func(int a, int b) {
    //@ assert (0 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) <= 100);
    int result;
    result = a * a - b * b;
    //@ assert result == a * a - b * b;
    return result;
}

/*@
    requires 0 <= side <= 100;
    ensures \result == side * side * side;
*/
int cube_volume_func(int side) {
    //@ assert (0 <= (side) && (side) <= 100);
    int result;
    result = side * side * side;
    //@ assert result == side * side * side;
    return result;
}

int main() {
    return 0;
}
