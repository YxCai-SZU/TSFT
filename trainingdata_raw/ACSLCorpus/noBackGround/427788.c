#include <stdint.h>

/*@
  requires \valid_read(v + (0..3));
  requires ((4) == 4 &&
      0 <= (v)[0] && (v)[0] <= 10000 &&
      0 <= (v)[1] && (v)[1] <= 10000 &&
      0 <= (v)[2] && (v)[2] <= 10000 &&
      0 <= (v)[3] && (v)[3] <= 10000);
  ensures \result >= 0;
  ensures \result == ((v[0]) * (v[1])) || \result == ((v[2]) * (v[3]));
*/
uint32_t func(uint32_t* v) {
    uint32_t a;
    uint32_t b;
    uint32_t res;

    //@ assert ((v[0]) * (v[1])) <= 100000000;
    a = v[0] * v[1];
    
    //@ assert ((v[2]) * (v[3])) <= 100000000;
    b = v[2] * v[3];

    if (a > b) {
        res = a;
    } else {
        res = b;
    }

    return res;
}
