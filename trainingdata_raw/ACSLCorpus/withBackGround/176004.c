#include <stdbool.h>

/*@ predicate vector_len_range(integer len) = 1 <= len <= 3; */
/*@ predicate element_in_range(int *v, integer len) = 
      \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 9; */

/*@ lemma len_implies_access: 
      \forall int *v, integer len; 
      vector_len_range(len) && len > 2 ==> 0 <= 2 < len; */

/*@ requires \valid(v+(0..2));
    requires vector_len_range(3);
    requires element_in_range(v, 3);
    ensures \result == (v[2] == v[1] + v[0]);
    assigns \nothing;
*/
bool func(int *v) {
    //@ assert vector_len_range(3);
    //@ assert element_in_range(v, 3);
    //@ assert 0 <= 2 < 3;
    
    if (v[2] == v[1] + v[0]) {
        return true;
    } else {
        return false;
    }
}

/*@ requires \valid(v+(0..2));
    requires vector_len_range(3);
    requires element_in_range(v, 3);
    ensures \result == (v[2] == v[1] + v[0]);
    assigns \nothing;
*/
bool func2(int *v) {
    int a;
    int b;
    int c;
    
    //@ assert vector_len_range(3);
    //@ assert element_in_range(v, 3);
    //@ assert 0 <= 2 < 3;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    if (c == b + a) {
        return true;
    } else {
        return false;
    }
}
