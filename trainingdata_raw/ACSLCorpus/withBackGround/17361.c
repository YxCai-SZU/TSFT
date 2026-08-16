/*@
    predicate pos(integer x) = x > 0;
    lemma example_lemma: \forall integer x; pos(x) ==> x + 5 > 5;
*/

/*@
    requires x > 0;
    ensures \result > 5;
*/
int example(int x)
{
    int result;
    //@ assert x > 0;
    result = x + 5;
    //@ assert result > 5;
    return result;
}

int main()
{
    return 0;
}
