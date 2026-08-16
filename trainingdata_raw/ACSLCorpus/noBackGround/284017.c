#include <stdbool.h>

/*@
  requires 1 <= n <= 100;
  requires 0 <= x <= n * 3;
  ensures \result == (n <= x);
*/
bool func(int n, int x) {
    int max_money;
    bool result;

    max_money = n * 3;
    //@ assert max_money == n * 3;
    result = (n <= x);
    return result;
}
