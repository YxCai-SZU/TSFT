/*@
    predicate positive(integer v) = v > 0;

    lemma sum_lemma:
        \forall integer x, y;
            positive(x) && positive(y) ==> x + y > x;

    lemma sum_three_lemma:
        \forall integer x, y, z;
            positive(x) && positive(y) && positive(z) ==> x + y + z > x;

    lemma sum_n_lemma:
        \forall integer x, n;
            positive(x) && positive(n) ==> x + n > x;
*/

/*@
    requires positive(x) && positive(y);
    ensures \result > x;
*/
int lemma_sum(int x, int y)
{
    //@ assert x + y > x;
    return x + y;
}

/*@
    requires positive(x) && positive(y);
    ensures \result > x;
*/
int calc_example_8(int x, int y)
{
    int result;
    //@ assert x + y > x;
    result = x + y;
    return result;
}

/*@
    requires positive(x) && positive(y) && positive(z);
    ensures \result > x;
*/
int lemma_sum_three(int x, int y, int z)
{
    //@ assert x + y > x;
    //@ assert x + y + z > x;
    return x + y + z;
}

/*@
    requires positive(x) && positive(y) && positive(z);
    ensures \result > x;
*/
int calc_example_9(int x, int y, int z)
{
    int result;
    //@ assert x + y + z > x;
    result = x + y + z;
    return result;
}

/*@
    requires positive(x) && positive(n);
    ensures \result > x;
*/
int lemma_sum_n(int x, int n)
{
    //@ assert x + n > x;
    return x + n;
}

/*@
    requires positive(x) && positive(n);
    ensures \result > x;
*/
int calc_example_10(int x, int n)
{
    int result;
    //@ assert x + n > x;
    result = x + n;
    return result;
}

int main()
{
    return 0;
}
