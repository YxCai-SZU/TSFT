/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_in_range:
        \forall integer x, y;
            in_range(x) && in_range(y) ==>
            -1000000000000000000 <= product(x, y) <= 1000000000000000000;
*/

/*@
    requires -1000000000 <= a <= 1000000000;
    requires -1000000000 <= b <= 1000000000;
    requires a <= b;
    requires -1000000000 <= c <= 1000000000;
    requires -1000000000 <= d <= 1000000000;
    requires c <= d;
    ensures \result == a*d || \result == b*c || \result == a*c || \result == b*d;
*/
long func(long a, long b, long c, long d) {
    long max_value;
    long temp1;
    long temp2;
    long temp3;
    long temp4;

    //@ assert in_range(a);
    //@ assert in_range(c);
    //@ assert -1000000000000000000 <= a*c <= 1000000000000000000;
    //@ assert -1000000000000000000 <= a*d <= 1000000000000000000;
    //@ assert -1000000000000000000 <= b*c <= 1000000000000000000;
    //@ assert -1000000000000000000 <= b*d <= 1000000000000000000;

    temp1 = a * c;
    temp2 = a * d;
    temp3 = b * c;
    temp4 = b * d;

    max_value = (temp1 > temp2) ? temp1 : temp2;
    max_value = (max_value > temp3) ? max_value : temp3;
    max_value = (max_value > temp4) ? max_value : temp4;

    //@ assert max_value == a*d || max_value == b*c || max_value == a*c || max_value == b*d;
    return max_value;
}
