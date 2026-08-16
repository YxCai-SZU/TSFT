#include <stdbool.h>

/*@ requires \valid(v+(0..2));
    requires v[0] >= -100 && v[1] <= 100 && v[2] >= 0;
    requires v[0] <= v[1];
    requires v[2] <= 100;
    ensures \result == (v[1] >= v[0] + v[2]);
    assigns \nothing;
*/
bool func(long v[3]) {
    long l;
    long r;
    long d;

    //@ assert v[0] >= -100 && v[0] <= 100;
    //@ assert v[1] >= -100 && v[1] <= 100;
    //@ assert v[2] >= 0 && v[2] <= 100;
    //@ assert v[0] <= v[1];
    //@ assert v[2] <= 100;
    //@ assert v[0] + v[2] <= 200;

    l = v[0];
    r = v[1];
    d = v[2];

    //@ assert ((l) >= -100 && (l) <= 100 &&       (r) >= -100 && (r) <= 100 &&       (d) >= 0 && (d) <= 100 &&       (l) <= (r) &&       (l) + (d) <= 200);
    //@ assert l + d <= 200;

    return r >= l + d;
}
