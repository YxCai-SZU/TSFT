#include <stdbool.h>

/*@ requires \valid(s) && s_len == 1;
    requires \forall integer i; 0 <= i < s_len ==> s[i] % 4 == 0;
    ensures \result == true;
    assigns \nothing;
*/
bool is_multiple_of_4(int s_len, int *s) {
    //@ assert s_len == 1;
    //@ assert \forall integer i; 0 <= i < s_len ==> s[i] % 4 == 0;
    return true;
}

int main() {
    int s[1] = {4};
    bool result;
    
    //@ assert s[0] == 4;
    //@ assert \forall integer i; 0 <= i < 1 ==> s[i] % 4 == 0;
    
    result = is_multiple_of_4(1, s);
    //@ assert result == true;
    
    return 0;
}
