#include <stdbool.h>

/*@
    predicate valid_vec(int *v) =
        \valid(v) && \valid(v+1) && \valid(v+2) &&
        v[0] >= -100 && v[0] <= 100 &&
        v[1] >= -100 && v[1] <= 100 &&
        v[2] >= -100 && v[2] <= 100 &&
        v[1] != v[2];
*/

/*@
    logic integer vec_at{L}(int *v, integer i) = v[i];
*/

/*@
    lemma vec_property:
        \forall int *v; valid_vec(v) ==>
            (vec_at(v,0) == vec_at(v,1) && vec_at(v,1) != vec_at(v,2)) ||
            (vec_at(v,0) == vec_at(v,2) && vec_at(v,2) != vec_at(v,1)) ||
            (vec_at(v,0) != vec_at(v,1) && vec_at(v,0) != vec_at(v,2));
*/

/*@
    requires valid_vec(v);
    ensures
        (vec_at(v,0) == vec_at(v,1) && \result == vec_at(v,2)) ||
        (vec_at(v,0) == vec_at(v,2) && \result == vec_at(v,1)) ||
        (vec_at(v,0) != vec_at(v,1) && vec_at(v,0) != vec_at(v,2) && \result == vec_at(v,0));
    assigns \nothing;
*/
int func(int *v)
{
    int result;
    
    //@ assert valid_vec(v);
    
    if (v[0] == v[1]) {
        //@ assert vec_at(v,0) == vec_at(v,1);
        result = v[2];
    } else if (v[0] == v[2]) {
        //@ assert vec_at(v,0) == vec_at(v,2);
        result = v[1];
    } else {
        //@ assert vec_at(v,0) != vec_at(v,1) && vec_at(v,0) != vec_at(v,2);
        result = v[0];
    }
    
    return result;
}

int main() {
    return 0;
}
