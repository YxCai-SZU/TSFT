#include <stdbool.h>

/*@ requires \valid(v + (0..2));
    requires v[0] >= 1 && v[0] <= 100;
    requires v[1] >= 1 && v[1] <= 100;
    requires v[2] >= 1 && v[2] <= 100;
    requires v[0] != v[1] && v[0] != v[2] && v[1] != v[2];
    assigns \nothing;
    ensures \result == true <==> (v[0] < v[1] && v[1] < v[2] || v[0] > v[1] && v[1] > v[2]);
*/
bool func(int v[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    if ((a < b && b < c) || (a > b && b > c)) {
        result = true;
    } else {
        //@ assert !(a < b && b < c || a > b && b > c);
        result = false;
    }
    return result;
}
