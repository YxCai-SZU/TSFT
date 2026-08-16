#include <stdbool.h>

/*@
    requires \valid_read(v + (0 .. 2));
    ensures \result == true <==> (((\forall integer k; (0) <= k < (1) ==> ((v))[k] < ((v))[k+1]) && (\forall integer k; (1) <= k < (2) ==> ((v))[k] < ((v))[k+1])) ||
        ((\forall integer k; (0) <= k < (1) ==> ((v))[k] > ((v))[k+1]) && (\forall integer k; (1) <= k < (2) ==> ((v))[k] > ((v))[k+1])));
    ensures \result == false <==> !(((\forall integer k; (0) <= k < (1) ==> ((v))[k] < ((v))[k+1]) && (\forall integer k; (1) <= k < (2) ==> ((v))[k] < ((v))[k+1])) ||
        ((\forall integer k; (0) <= k < (1) ==> ((v))[k] > ((v))[k+1]) && (\forall integer k; (1) <= k < (2) ==> ((v))[k] > ((v))[k+1])));
    assigns \nothing;
*/
bool func(int *v) {
    bool result;
    
    //@ assert v[0] < v[1] && v[1] < v[2] ==> (((\forall integer k; (0) <= k < (1) ==> ((v))[k] < ((v))[k+1]) && (\forall integer k; (1) <= k < (2) ==> ((v))[k] < ((v))[k+1])) ||         ((\forall integer k; (0) <= k < (1) ==> ((v))[k] > ((v))[k+1]) && (\forall integer k; (1) <= k < (2) ==> ((v))[k] > ((v))[k+1])));
    if (v[0] < v[1] && v[1] < v[2]) {
        result = true;
    } else if (v[0] > v[1] && v[1] > v[2]) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> (((\forall integer k; (0) <= k < (1) ==> ((v))[k] < ((v))[k+1]) && (\forall integer k; (1) <= k < (2) ==> ((v))[k] < ((v))[k+1])) ||         ((\forall integer k; (0) <= k < (1) ==> ((v))[k] > ((v))[k+1]) && (\forall integer k; (1) <= k < (2) ==> ((v))[k] > ((v))[k+1])));
    return result;
}
