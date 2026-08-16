#include <stdbool.h>

/*@
    requires \valid(v + (0..1));
    requires (1 <= (v[0]) <= 100);
    requires (1 <= (v[1]) <= 100);
    ensures \result == 1 <==> ((v[0]) == (v[1]) || (v[1]) == (v[0]) + 1 || (v[0]) == (v[1]) + 1);
    assigns \nothing;
*/
bool func(int v[2]) {
    int a;
    int b;
    bool result;

    a = v[0];
    b = v[1];

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) == (b) || (b) == (a) + 1 || (a) == (b) + 1) <==> (a == b || b == a + 1 || a == b + 1);

    result = (a == b || b == a + 1 || a == b + 1);
    return result;
}
