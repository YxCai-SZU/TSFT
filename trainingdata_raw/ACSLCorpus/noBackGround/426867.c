#include <stdbool.h>

/*@
  requires (1 <= (n) && (n) <= 100 &&
      1 <= (k) && (k) <= 100);
  ensures ((\result) == true <==> (n) <= (k) * 2);
*/
bool func(int n, int k)
{
    // Variable declarations at top of scope
    bool result;

    if (n <= k * 2) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == true <==> n <= k * 2;
    return result;
}

/*@
  requires (1 <= (a) && (a) <= 7 &&
      1 <= (b) && (b) <= 7 &&
      1 <= (c) && (c) <= 7 &&
      1 <= (k) && (k) <= 7);
  ensures ((\result) == true <==> ((k) >= (a) + (b) || (k) >= (a) + (c) || (k) >= (b) + (c)));
*/
bool func1(int a, int b, int c, int k)
{
    // Variable declarations at top of scope
    bool is_enough;

    is_enough = false;
    
    if (k >= a + b) {
        is_enough = true;
    }
    if (k >= a + c) {
        is_enough = true;
    }
    if (k >= b + c) {
        is_enough = true;
    }

    //@ assert is_enough == true <==> (k >= a + b || k >= a + c || k >= b + c);
    return is_enough;
}
