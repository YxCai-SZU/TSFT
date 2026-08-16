#include <stdbool.h>
#include <stddef.h>

int main() {
    int pattern[2];
    int s[4];
    size_t pattern_len;
    size_t s_len;
    
    pattern[0] = 3;
    pattern[1] = 4;
    pattern_len = 2;
    
    s[0] = 1;
    s[1] = 2;
    s[2] = 3;
    s[3] = 4;
    s_len = 4;
    
    //@ assert ((pattern_len) <= (s_len) &&         \forall integer i; 0 <= i < (pattern_len) ==> (&s[0])[(s_len) - (pattern_len) + i] == (&pattern[0])[i]);
    
    return 0;
}

/*@
    requires 1 <= n <= 100;
    ensures \result == n * 2 * 3;
    assigns \nothing;
*/
int func(int n) {
    int pi;
    int result;
    
    pi = 3;
    result = n * 2 * pi;
    
    //@ assert result == n * 2 * 3;
    return result;
}

/*@
    requires 1 <= n <= 100;
    ensures \result == n * 2 * 3;
    assigns \nothing;
*/
int func2(int n) {
    int pi;
    int result;
    
    pi = 3;
    
    //@ assert n > 0;
    //@ assert n <= 100;
    //@ assert pi == 3;
    //@ assert n * 2 * pi == n * 2 * 3;
    
    result = n * 2 * pi;
    return result;
}
