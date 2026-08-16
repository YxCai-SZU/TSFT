#include <stdbool.h>

/*@ requires \valid(v+(0..2));
    requires \forall integer i; 0 <= i < 3 ==> 1 <= v[i] && v[i] <= 9;
    assigns \nothing;
    ensures \result == (v[0] < v[1] && v[1] < v[2]);
*/
bool is_increasing_sequence(int v[3]) {
    int a;
    int b;
    int c;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert (1 <= (a) && (a) <= 9);
    //@ assert (1 <= (b) && (b) <= 9);
    //@ assert (1 <= (c) && (c) <= 9);

    return a < b && b < c;
}
