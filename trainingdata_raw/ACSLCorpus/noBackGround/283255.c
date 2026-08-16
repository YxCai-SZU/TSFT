#include <stdbool.h>

/*@
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> (((v)[i]) == 0 || ((v)[i]) == 1));
    ensures \result == (
        (v[1] == 0 && v[2] == 1 && v[0] == 0) ||
        (v[1] == 1 && v[2] == 1 && v[0] == 0) ||
        (v[1] == 1 && v[2] == 0 && v[0] == 1) ||
        (v[1] == 1 && v[2] == 0 && v[0] == 0)
    );
    assigns \nothing;
*/
bool func(int *v) {
    int v0, v1, v2;
    bool result;

    v0 = v[0];
    v1 = v[1];
    v2 = v[2];

    //@ assert ((v0) == 0 || (v0) == 1) && ((v1) == 0 || (v1) == 1) && ((v2) == 0 || (v2) == 1);

    if (v1 == 0 && v2 == 1 && v0 == 0) {
        result = true;
        //@ assert result == true;
        return result;
    }
    if (v1 == 1 && v2 == 1 && v0 == 0) {
        result = true;
        //@ assert result == true;
        return result;
    }
    if (v1 == 1 && v2 == 0 && v0 == 1) {
        result = true;
        //@ assert result == true;
        return result;
    }
    if (v1 == 1 && v2 == 0 && v0 == 0) {
        result = true;
        //@ assert result == true;
        return result;
    }

    result = false;
    //@ assert result == false;
    return result;
}
