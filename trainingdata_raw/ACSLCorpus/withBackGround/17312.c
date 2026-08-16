/*@
    predicate example_10_pre(integer x) = 1 <= x && x <= 100;
    predicate example_10_post(integer x) = 1 <= x && x <= 100;
    lemma example_10_lemma: \forall integer x; example_10_pre(x) ==> example_10_post(x);
*/

/*@
    requires example_10_pre(x);
    ensures example_10_post(x);
*/
void func_example_10(int x)
{
    //@ assert 1 <= x && x <= 100;
}

/*@
    predicate example_11_pre(integer x) = 1 <= x && x <= 100;
    predicate example_11_post(integer x) = 1 <= x && x <= 100;
    lemma example_11_lemma: \forall integer x; example_11_pre(x) ==> example_11_post(x);
*/

/*@
    requires example_11_pre(x);
    ensures example_11_post(x);
*/
void func_example_11(int x)
{
    //@ assert 1 <= x && x <= 100;
}

int main()
{
    return 0;
}
