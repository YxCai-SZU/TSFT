#include <stdint.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 100; */

/*@
  requires valid_range(a) && valid_range(b) && valid_range(c);
  ensures \result >= 0 && \result <= 3;
  assigns \nothing;
*/
int64_t count_possible_triangles(int64_t a, int64_t b, int64_t c) {
    int64_t count = 0;
    
    //@ assert a + b > c ==> count + 1 >= 0;
    if (a + b > c) {
        count += 1;
    }
    
    //@ assert a + c > b ==> count + 1 >= 0;
    if (a + c > b) {
        count += 1;
    }
    
    //@ assert b + c > a ==> count + 1 >= 0;
    if (b + c > a) {
        count += 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= 3;
    
    return count;
}
