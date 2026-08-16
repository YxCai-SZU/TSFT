#include <limits.h>

/*@
    predicate bounds(integer v) = 1 <= v <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound:
        \forall integer x, y;
            bounds(x) && bounds(y) ==> product(x, y) <= 10000;
*/

/*@
    requires bounds(x) && bounds(y);
    ensures \result == product(x, y);
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert product(x, y) <= 10000;
    return x * y;
}

/*@
    requires bounds(x) && bounds(y);
    ensures \result == product(x, y);
    assigns \nothing;
*/
int func_ref(int x, int y)
{
    int result;
    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert product(x, y) <= 10000;
    result = x * y;
    return result;
}

/*@
    requires bounds(x) && bounds(y);
    ensures \result == product(x, y);
    assigns \nothing;
*/
int func_auto(int x, int y)
{
    int result;
    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert product(x, y) <= 10000;
    result = x * y;
    return result;
}

/*@
    requires bounds(x) && bounds(y);
    ensures product(x, y) <= 10000;
*/
void func_proof(int x, int y)
{
    //@ assert product(x, y) <= 10000;
}

/*@
    predicate tuple_bounds(int a, int b) = bounds(a) && bounds(b);
*/

/*@
    requires tuple_bounds(x1, x2) && tuple_bounds(y1, y2);
    ensures \result == product(x1, y1);
    assigns \nothing;
*/
int func_tuplex(int x1, int x2, int y1, int y2)
{
    //@ assert product(x1, y1) <= 10000;
    return x1 * y1;
}

/*@
    requires tuple_bounds(x1, x2) && tuple_bounds(y1, y2);
    ensures product(x1, y1) <= 10000;
*/
void func_tuplex_proof(int x1, int x2, int y1, int y2)
{
    //@ assert product(x1, y1) <= 10000;
}
