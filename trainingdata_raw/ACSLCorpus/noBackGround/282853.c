#include <stdbool.h>

/*@
  requires \valid(input + (0..1));
  requires (1 <= (input[0]) && (input[0]) <= 100);
  requires (1 <= (input[1]) && (input[1]) <= 100);
  ensures \result == (input[0] <= input[1]);
*/
bool func(const int input[2]) {
    int A;
    int B;
    bool result;

    A = input[0];
    B = input[1];

    //@ assert (1 <= (A) && (A) <= 100);
    //@ assert (1 <= (B) && (B) <= 100);

    result = (A <= B);
    return result;
}
