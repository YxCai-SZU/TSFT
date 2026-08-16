#include <stdbool.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 100; */

/*@
    requires \valid(v + (0..1));
    requires valid_range(v[0]) && valid_range(v[1]);
    ensures \result == (v[0] <= v[1]);
    assigns \nothing;
*/
bool func(int v[2]) {
    int v0;
    int v1;
    bool result;
    
    v0 = v[0];
    v1 = v[1];
    
    //@ assert valid_range(v0);
    //@ assert valid_range(v1);
    
    result = (v0 <= v1);
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    int v1[2] = {2, 7};
    int v2[2] = {7, 2};
    int v3[2] = {5, 5};
    
    bool r1 = func(v1);
    bool r2 = func(v2);
    bool r3 = func(v3);
    
    //@ assert r1 == true;
    //@ assert r2 == false;
    //@ assert r3 == true;
    
    return 0;
}
