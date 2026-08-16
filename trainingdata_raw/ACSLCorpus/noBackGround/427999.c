#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (m) && (m) <= 20);
    ensures \result == ((n) + (m)) || \result == ((n) * (m)) || \result == ((n) - (m));
    assigns \nothing;
*/
int func(int n, int m) {
    int sum;
    int diff;
    int prod;
    int max_val;

    //@ assert (1 <= (n) && (n) <= 20 &&         1 <= (m) && (m) <= 20);
    sum = n + m;
    diff = n - m;
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= m && m <= 20;
    //@ assert 1 <= n * m && n * m <= 400;
    prod = n * m;

    max_val = sum;
    if (diff > max_val) {
        max_val = diff;
    }
    if (prod > max_val) {
        max_val = prod;
    }

    //@ assert max_val == sum || max_val == diff || max_val == prod;
    //@ assert max_val == n + m || max_val == n * m || max_val == n - m;
    
    return max_val;
}

int main() {
    return 0;
}
