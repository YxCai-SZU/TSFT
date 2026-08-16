#include <stdbool.h>

/*@
  requires 1 <= n && n <= 10000;
  requires 1 <= x && x <= 100000;
  ensures \result == true <==> n * 50 >= x;
*/
bool func(unsigned long n, unsigned long x) {
    unsigned long current_balance = 0;
    unsigned long i = 0;

    /*@
      loop invariant ((i) >= 0 && (i) <= (n) &&
      (current_balance) == (i) * 50 &&
      (n) >= 1 && (n) <= 10000 &&
      (current_balance) <= 500000);
      loop assigns i, current_balance;
      loop variant n - i;
    */
    while (i < n) {
        current_balance += 50;
        i += 1;
    }

    //@ assert current_balance == n * 50;
    return current_balance >= x;
}
