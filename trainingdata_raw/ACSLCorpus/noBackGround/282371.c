#include <stdbool.h>

/*@
  requires 1 <= a <= 9;
  requires 1 <= b <= 9;
  requires 1 <= c <= 9;
  ensures \result == (((a == b) && (b != c)) || 
                      ((b == c) && (c != a)) || 
                      ((c == a) && (a != b)));
  assigns \nothing;
*/
bool func(int a, int b, int c) {
    bool a_equal_b;
    bool b_equal_c;
    bool c_equal_a;
    bool result;

    a_equal_b = (a == b);
    b_equal_c = (b == c);
    c_equal_a = (c == a);

    //@ assert a_equal_b == (a == b);
    //@ assert b_equal_c == (b == c);
    //@ assert c_equal_a == (c == a);

    result = (a_equal_b && !b_equal_c) || 
             (b_equal_c && !c_equal_a) || 
             (c_equal_a && !a_equal_b);

    return result;
}
