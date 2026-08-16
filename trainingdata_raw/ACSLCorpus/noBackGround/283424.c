#include <stdbool.h>
/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] && (v)[0] <= 100 &&
        1 <= (v)[1] && (v)[1] <= 20 &&
        1 <= (v)[2] && (v)[2] <= 2000);
    ensures (((v[0]) * (v[1])) < v[2] ==> \result == 1);
    ensures (((v[0]) * (v[1])) >= v[2] ==> \result == 0);
    assigns \nothing;
*/
int func(int *v) {
    int ans;
    //@ assert 1 <= v[0] && v[0] <= 100;
    //@ assert 1 <= v[1] && v[1] <= 20;
    //@ assert ((v[0]) * (v[1])) <= 2000;
    
    if (v[0] * v[1] < v[2]) {
        ans = 1;
    } else {
        ans = 0;
    }
    return ans;
}
