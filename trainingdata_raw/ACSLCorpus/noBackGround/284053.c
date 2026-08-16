#include <stdbool.h>

/*@ requires \valid(a+(0..len-1)) && \valid(b+(0..len-1));
    requires (\forall integer i; 0 <= i < (len) ==> \at((a)[i], Here) == \at((b)[i], Here));
    ensures \result == true;
    assigns \nothing;
*/
bool check(int *a, int *b, int len) {
    //@ assert (\forall integer i; 0 <= i < (len) ==> \at((a)[i], Here) == \at((b)[i], Here));
    return true;
}

/*@ assigns \nothing;
*/
int main() {
    return 0;
}
