#include <stdbool.h>

/*@
    requires \valid(v + (0 .. 1));
    requires ((2) == 2 &&
        \forall integer i; 0 <= i < (2) ==> (v)[i] > 0 && (v)[i] <= 100);
    ensures \result == true <==> v[0] % 2 == 0 || v[1] % 2 == 0;
    ensures ((\result) == true <==> (v[0]) % 2 == 0 || (v[1]) % 2 == 0);
*/
bool func(int *v) {
    int a;
    int b;
    bool is_a_even;
    bool is_b_even;
    bool result;

    a = v[0];
    b = v[1];

    //@ assert a > 0 && a <= 100;
    //@ assert b > 0 && b <= 100;

    is_a_even = (a % 2 == 0);
    is_b_even = (b % 2 == 0);

    //@ assert is_a_even == (a % 2 == 0);
    //@ assert is_b_even == (b % 2 == 0);

    result = is_a_even || is_b_even;

    //@ assert result == true <==> v[0] % 2 == 0 || v[1] % 2 == 0;
    return result;
}
