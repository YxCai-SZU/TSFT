#include <stdbool.h>

/*@ predicate valid_vector(int *v) =
      \valid(v) && \valid(v+1) && \valid(v+2) &&
      v[0] >= 1 && v[0] <= 9 &&
      v[1] >= 1 && v[1] <= 9 &&
      v[2] >= 1 && v[2] <= 9;
*/

/*@ logic integer diff_a_b(integer a, integer b) = b - a; */

/*@ logic integer diff_b_c(integer b, integer c) = c - b; */

/*@ lemma diff_bounds: 
      \forall integer a,b,c; 
      (a >= 1 && a <= 9 && b >= 1 && b <= 9 && c >= 1 && c <= 9) ==> 
      (b - a >= -8 && b - a <= 8 && c - b >= -8 && c - b <= 8);
*/

/*@ requires valid_vector(v);
    ensures \result == (v[1] - v[0] == v[2] - v[1]);
    assigns \nothing;
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    bool result;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    //@ assert a >= 1 && a <= 9;
    //@ assert b >= 1 && b <= 9;
    //@ assert c >= 1 && c <= 9;
    
    //@ assert b - a >= -8 && b - a <= 8;
    //@ assert c - b >= -8 && c - b <= 8;
    
    result = (b - a == c - b);
    
    //@ assert result == (v[1] - v[0] == v[2] - v[1]);
    return result;
}
