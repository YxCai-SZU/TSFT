#include <stdbool.h>

/*@
    requires \valid_read(s + (0..len-1));
    requires len >= 3;
    requires \forall integer i; 0 <= i < len - 1 ==> s[i] <= s[i+1];
    ensures \result == true;
    assigns \nothing;
*/
bool verify_sorted_property(const int *s, int len) {
    //@ assert s[0] <= s[1];
    //@ assert s[1] <= s[2];
    //@ assert s[0] <= s[2];
    return true;
}

/*@
    requires \valid_read(s + (0..len-1));
    requires len >= 3;
    requires \forall integer i; 0 <= i < len - 1 ==> s[i] <= s[i+1] && s[i] * 2 <= s[i+1] * 2;
    ensures \result == true;
    assigns \nothing;
*/
bool verify_double_sorted_property(const int *s, int len) {
    //@ assert s[0] <= s[1] && s[0] * 2 <= s[1] * 2;
    //@ assert s[1] <= s[2] && s[1] * 2 <= s[2] * 2;
    //@ assert s[0] <= s[2] && s[0] * 2 <= s[2] * 2;
    return true;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
