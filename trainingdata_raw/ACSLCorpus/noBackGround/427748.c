#include <limits.h>

/*@
    requires a >= INT_MIN && a <= INT_MAX;
    requires b >= INT_MIN && b <= INT_MAX;
    requires c >= INT_MIN && c <= INT_MAX;
    ensures \result == (a < b && b < c);
*/
int func(int a, int b, int c) {
    int max_value;
    int min_value;
    int result;

    max_value = a;
    //@ assert ((max_value) == (a) || (max_value) == (b) || (max_value) == (c));
    if (b > max_value) {
        max_value = b;
        //@ assert ((max_value) == (a) || (max_value) == (b) || (max_value) == (c));
    }
    if (c > max_value) {
        max_value = c;
        //@ assert ((max_value) == (a) || (max_value) == (b) || (max_value) == (c));
    }

    min_value = a;
    //@ assert ((min_value) == (a) || (min_value) == (b) || (min_value) == (c));
    if (b < min_value) {
        min_value = b;
        //@ assert ((min_value) == (a) || (min_value) == (b) || (min_value) == (c));
    }
    if (c < min_value) {
        min_value = c;
        //@ assert ((min_value) == (a) || (min_value) == (b) || (min_value) == (c));
    }

    //@ assert ((max_value) == (a) || (max_value) == (b) || (max_value) == (c));
    //@ assert ((min_value) == (a) || (min_value) == (b) || (min_value) == (c));

    if (a < b && b < c) {
        result = 1;
    } else {
        result = 0;
    }
    //@ assert result == (a < b && b < c);
    return result;
}
