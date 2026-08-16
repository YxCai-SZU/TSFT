/*@
    predicate in_range(integer v) = -1000 <= v <= 1000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> -1000000 <= product(x, y) <= 1000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == product(b, d) || \result == product(a, d) || \result == product(b, c) || \result == product(a, c);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_val;
    int temp_val;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);
    //@ assert a <= b;
    //@ assert c <= d;

    //@ assert -1000000 <= product(a, c) <= 1000000;
    max_val = a * c;

    //@ assert -1000000 <= product(a, d) <= 1000000;
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert -1000000 <= product(b, c) <= 1000000;
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert -1000000 <= product(b, d) <= 1000000;
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    return max_val;
}
