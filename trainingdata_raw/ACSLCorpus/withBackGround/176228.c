/*@
    predicate is_valid_range(integer v) = 1 <= v <= 10000;

    logic integer max(integer x, integer y) = (x > y) ? x : y;

    lemma max_choice:
        \forall integer x, y;
            max(x, y) == x || max(x, y) == y;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
*/
int func(int a, int b, int c, int d)
{
    int train_amount;
    int bus_amount;
    int result;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);

    train_amount = (a > b) ? a : b;
    //@ assert train_amount == a || train_amount == b;

    bus_amount = (c > d) ? c : d;
    //@ assert bus_amount == c || bus_amount == d;

    //@ assert train_amount + bus_amount == a + c || train_amount + bus_amount == a + d || train_amount + bus_amount == b + c || train_amount + bus_amount == b + d;

    result = train_amount + bus_amount;
    return result;
}
