/*@
predicate non_negative(integer x) = x >= 0;

lemma example2_lemma: \forall integer x; non_negative(x) ==> x <= x + 10;
*/

/*@
requires non_negative(x);
ensures \result == x;
assigns \nothing;
*/
int example2(int x)
{
    //@ assert x <= x + 10;
    return x;
}

int main()
{
    int x = 0;
    int result = example2(x);
    return 0;
}
