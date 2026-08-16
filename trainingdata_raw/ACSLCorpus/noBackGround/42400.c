#include <stdbool.h>

/*@
  requires (0 <= (a) <= 123) && (0 <= (b) <= 123) && (0 <= (c) <= 123) && (0 <= (d) <= 123) && (0 <= (e) <= 123) && (0 <= (k) <= 123);
  requires ((a) < (b) < (c) < (d) < (e));
  ensures \result == true <==> b - a <= k;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    // Variable declarations at the top
    int a_local = a;
    int b_local = b;
    int c_local = c;
    int d_local = d;
    int e_local = e;
    int k_local = k;
    bool result;

    if (b_local - a_local > k_local) {
        result = false;
    } else {
        //@ assert b_local - a_local <= k_local;
        result = true;
    }

    return result;
}
