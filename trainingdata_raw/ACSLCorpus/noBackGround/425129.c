#include <stdint.h>
#include <limits.h>

/*@
    requires \valid(v + (0..3));
    requires ((4) >= 4 &&
        1 <= (v)[0] <= 1000000000 &&
        1 <= (v)[1] <= 1000000000 &&
        1 <= (v)[2] <= 1000000000 &&
        1 <= (v)[3] <= 1000000000);
    assigns \nothing;
    ensures \result == ((v[0]) * (v[1])) || \result == ((v[2]) * (v[3]));
    ensures \result >= 1;
*/
int64_t func(int64_t* v) {
    int64_t a;
    int64_t b;
    int64_t c;
    int64_t d;
    int64_t product1;
    int64_t product2;
    int64_t max_value;

    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];

    //@ assert 1 <= a <= 1000000000;
    //@ assert 1 <= b <= 1000000000;
    //@ assert ((a) * (b)) >= 1;
    
    //@ assert 1 <= c <= 1000000000;
    //@ assert 1 <= d <= 1000000000;
    //@ assert ((c) * (d)) >= 1;

    product1 = a * b;
    product2 = c * d;

    //@ assert product1 == ((a) * (b));
    //@ assert product2 == ((c) * (d));

    if (product1 > product2) {
        max_value = product1;
        //@ assert max_value == ((a) * (b));
    } else {
        max_value = product2;
        //@ assert max_value == ((c) * (d));
    }

    //@ assert max_value == ((a) * (b)) || max_value == ((c) * (d));
    //@ assert max_value >= 1;

    return max_value;
}
