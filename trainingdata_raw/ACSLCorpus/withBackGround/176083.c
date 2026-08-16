/*@
predicate bounds(integer a, integer b, integer c) =
    a >= 1 && a <= 100 &&
    b >= 1 && b <= 100 &&
    c >= 1 && c <= 100;

lemma upper_bound:
    \forall integer a, integer b, integer c;
    bounds(a, b, c) ==> a * b * c <= 1000000;

lemma lower_bound:
    \forall integer a, integer b, integer c;
    bounds(a, b, c) ==> a * b * c >= 1;
*/

/*@
requires bounds(a, b, c);
ensures \result <= 1000000000;
*/
int non_linear_arith_example19(int a, int b, int c)
{
    //@ assert bounds(a, b, c);
    //@ assert a * b * c <= 1000000;
    return a * b * c;
}

/*@
requires bounds(a, b, c);
ensures \result >= 1;
*/
int non_linear_arith_example20(int a, int b, int c)
{
    //@ assert bounds(a, b, c);
    //@ assert a * b * c >= 1;
    return a * b * c;
}

int main()
{
    return 0;
}
