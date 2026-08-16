#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(v + (0..1));
    requires ((2) == 2);
    requires (1 <= (v[0]) && (v[0]) <= 100);
    requires (1 <= (v[1]) && (v[1]) <= 100);
    assigns \nothing;
    ensures ((\result) == ((v[0]) <= (v[1])));
*/
bool func(size_t v[2]) {
    size_t s;
    size_t w;
    bool result;

    //@ assert ((2) == 2);
    //@ assert (1 <= (v[0]) && (v[0]) <= 100);
    //@ assert (1 <= (v[1]) && (v[1]) <= 100);

    s = v[0];
    w = v[1];

    if (s <= w) {
        result = true;
    } else {
        result = false;
    }

    //@ assert ((result) == ((s) <= (w)));
    return result;
}
