#include <stdint.h>

/*@
  requires \valid(v + (0..2));
  requires v[0] >= 1 && v[0] <= 100;
  requires v[1] >= 1 && v[1] <= 100;
  requires v[2] >= 1 && v[2] <= 100;
  assigns \nothing;
  ensures \result == (v[0] > v[1] * v[2]) ? (v[1] * v[2]) / 2 : v[1] * v[2];
*/
int64_t func(int64_t* v) {
    int64_t a;
    int64_t b;
    int64_t x;
    int64_t product;
    int64_t result;
    
    a = v[0];
    b = v[1];
    x = v[2];
    
    //@ assert ((a) >= 1 && (a) <= 100 &&     (b) >= 1 && (b) <= 100 &&     (x) >= 1 && (x) <= 100);
    
    //@ assert ((b) * (x)) <= 10000;
    product = b * x;
    
    if (a > product) {
        //@ assert ((b) * (x)) / 2 <= 5000;
        result = product / 2;
        return result;
    } else {
        result = product;
        return result;
    }
}
