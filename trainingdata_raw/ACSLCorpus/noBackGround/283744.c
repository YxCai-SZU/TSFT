#include <stdint.h>

/*@
    requires (0 <= (h1) < 24 && 0 <= (m1) < 60);
    requires (0 <= (h2) < 24 && 0 <= (m2) < 60);
    requires ((h1) <= (h2) && ((h1) == (h2) ==> (m1) <= (m2)));
    requires 0 <= k < 60 * 24;
    ensures \result == (60 * ((h2) - (h1)) + (m2) - (m1) - (k));
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k) {
    int64_t ans;
    //@ assert 0 <= 60 * (h2 - h1) <= 60 * 24;
    //@ assert 0 <= 60 * (h2 - h1) + m2 - m1 <= 60 * 24 + 60;
    ans = 60 * (h2 - h1) + m2 - m1 - k;
    return ans;
}

int main() {
    return 0;
}
