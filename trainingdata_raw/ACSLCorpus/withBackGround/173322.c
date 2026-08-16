/*@
    predicate non_decreasing(integer a, integer b, integer c) = a <= b && b <= c;

    lemma triple_addition_lemma:
        \forall integer a, b, c;
            non_decreasing(a, b, c) ==> a + b + c <= c + c + c;

    lemma calc_example_lemma:
        \forall integer x, y;
            x >= 0 && y >= 0 ==> x * y <= y * x;
*/

/*@
    requires a <= b && b <= c;
    ensures \result <= c + c + c;
*/
int lemma_triple_addition(int a, int b, int c)
{
    //@ assert a + b + c <= c + c + c;
    return a + b + c;
}

/*@
    requires x >= 0 && y >= 0;
    ensures \result <= y * x;
*/
int calc_example_6(int x, int y)
{
    //@ assert x * y <= y * x;
    return x * y;
}

int main()
{
    return 0;
}
