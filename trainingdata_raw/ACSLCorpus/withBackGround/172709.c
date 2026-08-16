#include <stdbool.h>

/*@ predicate valid_vec(int *v) =
    v[0] >= 1 && v[0] <= 100 &&
    v[1] >= 1 && v[1] <= 100 &&
    v[2] >= 1 && v[2] <= 200;
*/

/*@ logic integer vec_len{L}(int *v) = 3; */

/*@ lemma vec_len_positive: \forall int *v; vec_len(v) > 0; */

/*@ requires n >= 1 && n <= 100;
    requires \valid(v+(0..2));
    requires valid_vec(v);
    ensures \result == (n >= v[2] - v[1] && n <= v[2] + v[0]);
*/
bool func(int n, int v[3]) {
    bool ret;
    
    //@ assert vec_len(v) == 3;
    
    if (n >= v[2] - v[1] && n <= v[2] + v[0]) {
        ret = true;
    } else {
        ret = false;
    }
    
    //@ assert ret == (n >= v[2] - v[1] && n <= v[2] + v[0]);
    
    return ret;
}
