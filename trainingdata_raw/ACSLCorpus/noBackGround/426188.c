#include <stdbool.h>

/*@ requires \valid(v + (0..3));
    requires ((4) == 4 &&
      (v)[0] >= 1 && (v)[0] <= 10000 &&
      (v)[1] >= 1 && (v)[1] <= 10000 &&
      (v)[2] >= 1 && (v)[2] <= 10000 &&
      (v)[3] >= 1 && (v)[3] <= 10000);
    ensures \result >= 0;
    ensures \result <= ((v[0]) * (v[1])) || \result <= ((v[2]) * (v[3]));
*/
int func(int* v) {
    int a;
    int b;
    int c;
    int d;
    int max1;
    int max2;
    int min_result;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert c >= 1 && c <= 10000;
    //@ assert d >= 1 && d <= 10000;

    //@ assert a * b <= 100000000;
    //@ assert c * d <= 100000000;

    if (a * b > c * d) {
        max1 = a * b;
    } else {
        max1 = c * d;
    }

    if (c * d > a * b) {
        max2 = c * d;
    } else {
        max2 = a * b;
    }

    if (max1 < max2) {
        min_result = max1;
    } else {
        min_result = max2;
    }

    //@ assert min_result >= 0;
    //@ assert min_result <= ((a) * (b)) || min_result <= ((c) * (d));

    return min_result;
}
