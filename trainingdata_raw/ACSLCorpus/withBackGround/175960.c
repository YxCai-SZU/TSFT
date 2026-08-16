/*@
    predicate in_range(integer v) = -1000 <= v <= 1000;

    logic integer sum(integer a, integer b) = a + b;
    logic integer product(integer a, integer b) = a * b;
    logic integer difference(integer a, integer b) = a - b;

    lemma product_in_range: \forall integer a, b; in_range(a) && in_range(b) ==> -1000000 <= product(a, b) <= 1000000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == sum(a, b) || \result == product(a, b) || \result == difference(a, b);
    ensures \result >= sum(a, b);
    ensures \result >= product(a, b);
    ensures \result >= difference(a, b);
*/
int func(int a, int b) {
    int x;
    int y;
    int z;
    int result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert -1000000 <= a * b <= 1000000;

    x = a + b;
    y = a * b;
    z = a - b;

    if (x > y) {
        if (x > z) {
            result = x;
        } else {
            result = z;
        }
    } else {
        if (y > z) {
            result = y;
        } else {
            result = z;
        }
    }

    //@ assert result == x || result == y || result == z;
    //@ assert result >= x;
    //@ assert result >= y;
    //@ assert result >= z;

    return result;
}
