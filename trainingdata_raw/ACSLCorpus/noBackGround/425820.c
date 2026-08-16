#include <stdbool.h>

/*@ requires \valid(v+(0..1));
    requires v[0] >= 1 && v[0] <= 100;
    requires v[1] >= 1 && v[1] <= 100;
    assigns \nothing;
    ensures \result == (v[0] == v[1] - 1 || v[0] == v[1] || v[0] == v[1] + 1);
*/
bool func(int v[2]) {
    int diff;
    //@ assert v[0] >= 1 && v[0] <= 100;
    //@ assert v[1] >= 1 && v[1] <= 100;
    
    if (v[1] > v[0]) {
        diff = v[1] - v[0];
    } else {
        diff = v[0] - v[1];
    }
    
    //@ assert ((diff) == ((v[1]) > (v[0]) ? (v[1]) - (v[0]) : (v[0]) - (v[1])));
    //@ assert 0 <= diff <= 99;
    
    if (diff <= 1) {
        //@ assert diff <= 1 ==> (v[0] == v[1] - 1 || v[0] == v[1] || v[0] == v[1] + 1);
        return true;
    } else {
        //@ assert diff > 1 ==> !(v[0] == v[1] - 1 || v[0] == v[1] || v[0] == v[1] + 1);
        return false;
    }
}
