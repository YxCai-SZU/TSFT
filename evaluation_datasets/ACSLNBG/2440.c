#include <limits.h>


long func(long a, long b, long c, long d) {
    long max_val;
    long temp_val;

    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    max_val = a * c;

    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    return max_val;
}
