/*@
    predicate valid_range(integer x) = 1 <= x && x <= 100;
    predicate valid_pair(integer a, integer b) = valid_range(a) && valid_range(b);
    logic integer safe_product(integer a, integer b) = a * b;
    logic integer safe_triple_square(integer r) = 3 * r * r;
*/

/*@
    requires valid_range(r);
    ensures \result == safe_triple_square(r);
    assigns \nothing;
*/
long func(long r)
{
    //@ assert valid_range(r);
    //@ assert safe_triple_square(r) <= 3 * 100 * 100;
    return 3 * r * r;
}

/*@
    requires valid_pair(a, b);
    ensures \result == safe_product(a, b);
    assigns \nothing;
*/
long input_int_tuple(long a, long b)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert safe_product(a, b) <= 100 * 100;
    return a * b;
}

/*@
    requires \valid(arr + (0..1));
    requires valid_range(arr[0]) && valid_range(arr[1]);
    ensures \result == safe_product(arr[0], arr[1]);
    assigns \nothing;
*/
long input_int_array(long arr[2])
{
    //@ assert valid_range(arr[0]);
    //@ assert valid_range(arr[1]);
    //@ assert safe_product(arr[0], arr[1]) <= 100 * 100;
    return arr[0] * arr[1];
}
