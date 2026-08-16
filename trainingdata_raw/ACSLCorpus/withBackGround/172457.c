#include <stdbool.h>

/*@ predicate valid_range(int *arr, integer len) =
      len == 3 &&
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 100;
*/

/*@ logic integer sum_of_two(int a, int b) = a + b;
*/

/*@ lemma sum_commutative:
      \forall int a, b; sum_of_two(a, b) == sum_of_two(b, a);
*/

/*@ requires \valid(x + (0..2));
    requires valid_range(x, 3);
    ensures \result == (x[0] + x[1] == 7 || x[1] + x[2] == 7 || x[0] + x[2] == 7);
*/
bool is_shichi_go_san(int *x) {
    int a;
    int b;
    int c;
    bool result;

    a = x[0];
    b = x[1];
    c = x[2];
    result = false;

    //@ assert a == x[0] && b == x[1] && c == x[2];
    //@ assert valid_range(x, 3) ==> (1 <= a && a <= 100);
    //@ assert valid_range(x, 3) ==> (1 <= b && b <= 100);
    //@ assert valid_range(x, 3) ==> (1 <= c && c <= 100);

    if (a + b == 7 || b + c == 7 || c + a == 7) {
        result = true;
    }

    //@ assert result == (a + b == 7 || b + c == 7 || c + a == 7);
    return result;
}
