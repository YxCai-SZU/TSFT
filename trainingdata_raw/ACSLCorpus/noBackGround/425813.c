#include <stdbool.h>

/*@ requires \valid_read(s+(0..len-1));
    requires len >= 3;
    requires \forall integer i; 0 <= i < len-1 ==> s[i] < s[i+1];
    ensures s[0] < s[2];
    assigns \nothing;
*/
void verify_increasing_property(int *s, int len) {
    //@ assert s[0] < s[1];
    //@ assert s[1] < s[2];
}

/*@ assigns \nothing; */
int main() {
    return 0;
}
