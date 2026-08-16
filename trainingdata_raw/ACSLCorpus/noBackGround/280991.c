#include <stdbool.h>

/*@ requires \valid(v+(0..5));
    requires (\forall integer i; 0 <= i < (6) ==> 0 <= (v)[i] <= 123);
    requires ((v)[4] - (v)[0] <= (v)[5]);
    ensures \result == true;
*/
bool func(int *v) {
    int len;
    int i;
    int d;
    int k;
    bool result;

    len = 6;
    i = 0;

    /*@ loop invariant 0 <= i <= len;
        loop invariant (\forall integer i; 0 <= i < (6) ==> 0 <= (v)[i] <= 123);
        loop invariant ((v)[4] - (v)[0] <= (v)[5]);
        loop invariant len == 6;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer i; 0 <= i < (6) ==> 0 <= (v)[i] <= 123);
        if (v[i] < 0 || v[i] > 123) {
            return false;
        }
        i = i + 1;
    }

    d = v[4] - v[0];
    k = v[5];

    if (d <= k) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == true;
    return result;
}

int main() {
    return 0;
}
