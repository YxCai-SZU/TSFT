#include <stdint.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate ordered(integer a, integer b) = a <= b;
    predicate product_in_range(integer x, integer y) = -1000000000000000000 <= x * y <= 1000000000000000000;
    
    lemma product_range_lemma:
        \forall integer x, y; in_range(x) && in_range(y) ==> product_in_range(x, y);
*/


int64_t func(int64_t a, int64_t b, int64_t c, int64_t d) {
    int64_t tmp[4];
    int64_t max_value;
    int64_t i;
    
    //@ assert in_range(a);
    //@ assert in_range(c);
    //@ assert product_in_range(a, c);
    tmp[0] = a * c;
    //@ assert tmp[0] == a * c;
    
    //@ assert in_range(a);
    //@ assert in_range(d);
    //@ assert product_in_range(a, d);
    tmp[1] = a * d;
    //@ assert tmp[1] == a * d;
    
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert product_in_range(b, c);
    tmp[2] = b * c;
    //@ assert tmp[2] == b * c;
    
    //@ assert in_range(b);
    //@ assert in_range(d);
    //@ assert product_in_range(b, d);
    tmp[3] = b * d;
    //@ assert tmp[3] == b * d;
    
    max_value = tmp[0];
    i = 1;
    
    
    while (i < 4) {
        if (tmp[i] > max_value) {
            max_value = tmp[i];
        }
        i++;
    }
    
    return max_value;
}
