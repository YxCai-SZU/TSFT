#include <stdbool.h>

/*@ predicate in_range(integer x) = 1 <= x <= 10000; */

/*@ predicate valid_vector(int* v, integer len) =
        len == 4 &&
        \valid(v + (0..3)) &&
        in_range(v[0]) &&
        in_range(v[1]) &&
        in_range(v[2]) &&
        in_range(v[3]); */

/*@ lemma product_bound: \forall integer a, b; 
        in_range(a) && in_range(b) ==> a * b <= 10000 * 10000; */

/*@ lemma max_product_choice: \forall integer a, b, c, d, max_val;
        in_range(a) && in_range(b) && in_range(c) && in_range(d) &&
        (max_val == a * b || max_val == c * d) ==>
        (max_val == a * b || max_val == c * d) &&
        (max_val <= a * b || max_val <= c * d); */

/*@ requires valid_vector(v, 4);
    ensures \result >= 0;
    ensures \result == v[0] * v[1] || \result == v[2] * v[3];
    ensures \result <= v[0] * v[1] || \result <= v[2] * v[3];
    assigns \nothing;
*/
int func(int* v) {
    int a;
    int b;
    int c;
    int d;
    int max_val;
    
    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);
    
    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;
    
    if (a * b > c * d) {
        max_val = a * b;
    } else {
        max_val = c * d;
    }
    
    //@ assert max_val == a * b || max_val == c * d;
    return max_val;
}
