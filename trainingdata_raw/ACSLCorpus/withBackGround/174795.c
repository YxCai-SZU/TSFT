/*@
    predicate bool_and(integer a, integer b, integer c) =
        a != 0 && b != 0 && c != 0;

    lemma calc_example_logical_layers:
        \forall integer a, b, c;
        bool_and(a, b, c) ==> (a != 0 && b != 0) == (b != 0 && c != 0);

    predicate arith_range(integer a, integer b) =
        a == b && 0 <= a && a <= 5;

    lemma calc_example_arith:
        \forall integer a, b;
        arith_range(a, b) ==> a * 2 <= 10;

    lemma calc_example_arith2:
        \forall integer a, b;
        arith_range(a, b) ==> a * 3 <= 15;
*/

#include <stdbool.h>

/*@
    requires bool_and(a, b, c);
    ensures \result == ((a && b) == (b && c));
*/
bool logical_layers_example(bool a, bool b, bool c)
{
    //@ assert a != 0;
    //@ assert b != 0;
    //@ assert c != 0;
    //@ assert (a && b) == (b && c);
    return (a && b) == (b && c);
}

/*@
    requires arith_range(a, b);
    ensures \result == (a * 2 <= 10);
*/
bool arith_example(int a, int b)
{
    //@ assert 0 <= a && a <= 5;
    //@ assert a * 2 <= 10;
    return a * 2 <= 10;
}

/*@
    requires arith_range(a, b);
    ensures \result == (a * 3 <= 15);
*/
bool arith_example2(int a, int b)
{
    //@ assert 0 <= a && a <= 5;
    //@ assert a * 3 <= 15;
    return a * 3 <= 15;
}

int main()
{
    return 0;
}
