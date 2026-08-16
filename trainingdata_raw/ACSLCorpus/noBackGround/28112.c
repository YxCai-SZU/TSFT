#include <stdbool.h>

/*@
  requires \valid_read(input + (0..1));
  requires (1 <= (input[0]) && (input[0]) <= 12);
  requires (1 <= (input[1]) && (input[1]) <= 31);
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> ((input[0]) == 1 || (input[0]) == 3 || (input[0]) == 5 || (input[0]) == 7 || (input[0]) == 8 || (input[0]) == 10 || (input[0]) == 12) && input[1] == 5;
*/
int func(const int input[2]) {
    int a;
    int b;
    int result;

    a = input[0];
    b = input[1];

    if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12) {
        if (b == 5) {
            result = 1;
        } else {
            result = 0;
        }
    } else {
        result = 0;
    }

    //@ assert result == 0 || result == 1;
    return result;
}
