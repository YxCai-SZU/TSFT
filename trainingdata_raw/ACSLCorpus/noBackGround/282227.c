#include <stdbool.h>

/*@
  requires \valid_read(arr + (0 .. 2));
  requires ((3) == 3 &&
      \forall integer i; (0 <= (i) && (i) < ((3))) ==> (1 <= ((arr)[i]) && ((arr)[i]) <= 13));
  ensures \result == ((((arr[1]) == (arr[0]) + (arr[2])) ? 1 : (((arr[2]) == (arr[0]) + (arr[1])) ? 1 : (((arr[0]) == (arr[2]) + (arr[1])) ? 1 : 0))) == 1);
*/
bool func(const int *arr) {
    int a;
    int b;
    int c_temp;
    int c = 0;

    //@ assert ((3) == 3 &&       \forall integer i; (0 <= (i) && (i) < ((3))) ==> (1 <= ((arr)[i]) && ((arr)[i]) <= 13));
    a = arr[0];
    b = arr[1];
    c_temp = arr[2];

    if (a + b == c_temp) {
        c += 1;
    }
    if (a + c_temp == b) {
        c += 1;
    }
    if (b + c_temp == a) {
        c += 1;
    }

    //@ assert c == 1 ==> (((b) == (a) + (c_temp)) ? 1 : (((c_temp) == (a) + (b)) ? 1 : (((a) == (c_temp) + (b)) ? 1 : 0))) == 1;
    return c == 1;
}
