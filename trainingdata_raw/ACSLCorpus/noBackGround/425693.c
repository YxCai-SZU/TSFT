#include <stdbool.h>

/*@
  requires \valid(v+(0..2));
  requires (-100 <= (v[0]) && (v[0]) <= 100) && (-100 <= (v[1]) && (v[1]) <= 100) && (-100 <= (v[2]) && (v[2]) <= 100);
  ensures (v[0] == v[1] && \result == v[2]) ||
          (v[1] == v[2] && \result == v[0]) ||
          (v[0] == v[2] && \result == v[1]) ||
          (v[0] != v[1] && v[1] != v[2] && v[0] != v[2] && \result == -1);
  assigns \nothing;
*/
long func(const long v[3]) {
    long a;
    long b;
    long c;
    long result;

    a = v[0];
    b = v[1];
    c = v[2];

    if (a == b) {
        result = c;
        //@ assert v[0] == v[1] && result == v[2];
        return result;
    } else if (b == c) {
        result = a;
        //@ assert v[1] == v[2] && result == v[0];
        return result;
    } else if (a == c) {
        result = b;
        //@ assert v[0] == v[2] && result == v[1];
        return result;
    }

    //@ assert -1 >= -100 && -1 <= 100;
    result = -1;
    //@ assert v[0] != v[1] && v[1] != v[2] && v[0] != v[2] && result == -1;
    return result;
}
