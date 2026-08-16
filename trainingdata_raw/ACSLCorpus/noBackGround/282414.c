#include <stdbool.h>

/*@
  requires 1 <= input <= 9;
  ensures \result == (input == 3 || input == 5 || input == 7);
  assigns \nothing;
*/
bool func(int input)
{
    int a;
    int b;
    int c;
    bool ans;

    a = 3;
    b = 5;
    c = 7;
    ans = (input == a || input == b || input == c);

    //@ assert ans == (input == 3 || input == 5 || input == 7);

    return ans;
}
