#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> (((a) + (b) == (c)) || ((b) + (c) == (a)) || ((a) + (c) == (b)));
*/
bool can_distribute_evenly(int a, int b, int c) {
    int sum1;
    int sum2;
    int sum3;
    bool result;

    sum1 = a + b;
    sum2 = b + c;
    sum3 = a + c;

    if (sum1 == c || sum2 == a || sum3 == b) {
        //@ assert sum1 == c || sum2 == a || sum3 == b;
        result = true;
    } else {
        //@ assert sum1 != c && sum2 != a && sum3 != b;
        result = false;
    }

    //@ assert result == true <==> (((a) + (b) == (c)) || ((b) + (c) == (a)) || ((a) + (c) == (b)));
    return result;
}
