#include <stdbool.h>

/*@ requires (0 <= (n) && (n) <= 5 &&
      0 <= (k) && (k) <= 5 &&
      (n) <= (k));
    ensures ((n) * (n) <= (k) * (n));
*/
void calc_example_6(int n, int k) {
    //@ assert (0 <= (n) && (n) <= 5 &&       0 <= (k) && (k) <= 5 &&       (n) <= (k));
    //@ assert ((n) * (n) <= (k) * (n));
}

/*@ requires (0 <= (n) && (n) <= 10 &&
      0 <= (m) && (m) <= 10 &&
      (n) <= (m));
    ensures ((n) + (m) <= (m) + (m));
*/
void calc_example_7(int n, int m) {
    //@ assert (0 <= (n) && (n) <= 10 &&       0 <= (m) && (m) <= 10 &&       (n) <= (m));
    //@ assert ((n) + (m) <= (m) + (m));
}

int main() {
    return 0;
}
