#include <stdbool.h>

/*@
    requires \valid_read(s + (0..len-1));
    requires (\forall integer i; 0 <= i < (len) ==> (s)[i] > (threshold));
    ensures \result == true;
*/
bool greater_than_threshold(int *s, int len, int threshold) {
    //@ assert (\forall integer i; 0 <= i < (len) ==> (s)[i] > (threshold));
    return true;
}

int main() {
    int v[3] = {1, 2, 3};
    //@ assert (\forall integer i, j; 0 <= i < j < (3) ==> (&v[0])[i] != (&v[0])[j]);
    bool res = greater_than_threshold(&v[0], 3, 0);
    //@ assert res == true;
    return 0;
}
