#include <stdbool.h>

/*@ predicate valid_vector(int *v, integer len) =
    len == 3 &&
    1 <= v[0] <= 100 &&
    1 <= v[1] <= 100 &&
    1 <= v[2] <= 200;
*/

/*@ logic integer vector_len(int *v) = 3; */

/*@
    lemma vector_len_positive: \forall int *v; valid_vector(v, vector_len(v)) ==> vector_len(v) > 0;
*/

/*@
    requires \valid(v+(0..2));
    requires valid_vector(v, 3);
    ensures \result == (v[0] <= v[2] && v[0] + v[1] >= v[2]);
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    
    //@ assert v[0] == v[0];
    a = v[0];
    
    //@ assert v[1] == v[1];
    b = v[1];
    
    //@ assert v[2] == v[2];
    c = v[2];
    
    //@ assert a <= c && a + b >= c ==> (a <= c && a + b >= c);
    return a <= c && a + b >= c;
}
