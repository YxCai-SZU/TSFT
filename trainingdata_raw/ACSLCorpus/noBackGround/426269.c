#include <stdbool.h>

/*@
  requires 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
  ensures \result == (a < b && b < c);
  assigns \nothing;
*/
bool is_increasing_sequence(unsigned long long a, unsigned long long b, unsigned long long c) {
    bool result;
    result = a < b && b < c;
    return result;
}

/*@
  requires 1 <= n <= 10000 && 1 <= k <= 10000 && 1 <= y < x <= 10000;
  ensures \result == n * x || \result == k * x + (n - k) * y;
  assigns \nothing;
*/
int func(int n, int k, int x, int y) {
    int result;
    if (n <= k) {
        //@ assert n * x <= 100000000;
        result = n * x;
    } else {
        //@ assert k * x <= 100000000;
        //@ assert (n - k) * y <= 100000000;
        result = k * x + (n - k) * y;
    }
    return result;
}
