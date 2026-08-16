/*@
    predicate non_negative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;

    predicate k_valid(integer a, integer b, integer c, integer k) =
        k >= 1 && k <= a + b + c && k <= 2000000000;

    lemma count_bound:
        \forall integer a, b, c, k, k_flag, count;
        non_negative(a, b, c) && k_valid(a, b, c, k) &&
        0 <= k_flag <= k && count <= k_flag ==>
        count <= k;
*/

/*@
    requires non_negative(a, b, c) && k_valid(a, b, c, k);
    ensures \result <= k;
*/
int func(int a, int b, int c, int k)
{
    int k_flag = 0;
    int count = 0;
    int i = 0;

    //@ assert 0 <= i <= a;
    //@ assert 0 <= k_flag <= k;
    //@ assert k_flag <= i + k_flag;
    //@ assert count <= k_flag;
    //@ assert non_negative(a, b, c);
    //@ assert k_valid(a, b, c, k);

    /*@
        loop invariant 0 <= i <= a;
        loop invariant 0 <= k_flag <= k;
        loop invariant k_flag <= i + k_flag;
        loop invariant count <= k_flag;
        loop invariant non_negative(a, b, c);
        loop invariant k_valid(a, b, c, k);
        loop assigns k_flag, count, i;
        loop variant a - i;
    */
    while (i < a && k_flag < k) {
        k_flag += 1;
        count += 1;
        i += 1;
    }

    i = 0;
    //@ assert 0 <= i <= b;
    //@ assert 0 <= k_flag <= k;
    //@ assert k_flag <= i + k_flag;
    //@ assert count <= k;
    //@ assert non_negative(a, b, c);
    //@ assert k_valid(a, b, c, k);

    /*@
        loop invariant 0 <= i <= b;
        loop invariant 0 <= k_flag <= k;
        loop invariant k_flag <= i + k_flag;
        loop invariant count <= k;
        loop invariant non_negative(a, b, c);
        loop invariant k_valid(a, b, c, k);
        loop assigns k_flag, i;
        loop variant b - i;
    */
    while (i < b && k_flag < k) {
        k_flag += 1;
        i += 1;
    }

    i = 0;
    //@ assert 0 <= i <= c;
    //@ assert 0 <= k_flag <= k;
    //@ assert k_flag <= i + k_flag;
    //@ assert count <= k;
    //@ assert non_negative(a, b, c);
    //@ assert k_valid(a, b, c, k);

    /*@
        loop invariant 0 <= i <= c;
        loop invariant 0 <= k_flag <= k;
        loop invariant k_flag <= i + k_flag;
        loop invariant count <= k;
        loop invariant non_negative(a, b, c);
        loop invariant k_valid(a, b, c, k);
        loop assigns k_flag, i;
        loop variant c - i;
    */
    while (i < c && k_flag < k) {
        k_flag += 1;
        i += 1;
    }

    //@ assert count <= k;
    return count;
}
