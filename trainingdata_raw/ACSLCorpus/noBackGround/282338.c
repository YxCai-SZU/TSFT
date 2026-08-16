#include <stddef.h>

/*@
    requires k > 0;
    requires ((s_len) >= 0 && \valid((s) + (0 .. (s_len)-1)));
    ensures \result == ((s_len) < (k) ? 0 : (s_len) - (k) + 1);
    assigns \nothing;
*/
size_t count_k_length_substrings(const char *s, size_t s_len, size_t k) {
    size_t count;
    
    if (s_len < k) {
        count = 0;
    } else {
        //@ assert s_len >= k;
        //@ assert s_len - k + 1 <= s_len;
        count = s_len - k + 1;
    }
    
    return count;
}

int main() {
    return 0;
}
