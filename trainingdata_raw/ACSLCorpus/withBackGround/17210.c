/*@
    predicate lower_bound(integer x) = -100 <= x;
    predicate upper_bound(integer x) = x <= 100;
    predicate final_range(integer expr) = -98 <= expr <= 102;

    lemma func_lemma: \forall integer x; lower_bound(x) && upper_bound(x) ==> final_range(x + 2);
*/

/*@
    requires -100 <= x <= 100;
    ensures -98 <= x + 2 <= 102;
*/
void func(int x)
{
    //@ assert x + 2 >= -98;
    //@ assert x + 2 <= 102;
    //@ assert -98 <= x + 2 <= 102;
}
