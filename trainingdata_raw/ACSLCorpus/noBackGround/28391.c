#include <stdbool.h>

/*@ requires \valid(v + (0..2));
    requires (\forall integer i; (0 <= (i) < ((3))) ==> (1 <= ((v)[i]) && ((v)[i]) <= 9));
    ensures \result == 1 <==> ((3) == 3 && (v)[0] < (v)[1] && (v)[1] < (v)[2]);
    assigns \nothing;
*/
bool is_increasing(int v[3]) {
    //@ assert v[0] < v[1] && v[1] < v[2] || v[0] >= v[1] || v[1] >= v[2];
    
    return v[0] < v[1] && v[1] < v[2];
}

int main() {
    return 0;
}
