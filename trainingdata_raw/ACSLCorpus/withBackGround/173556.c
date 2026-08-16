/*@
predicate gt_chain(integer a, integer b, integer c) = a > b && b > c;

lemma transitive_gt:
    \forall integer a, b, c;
    gt_chain(a, b, c) ==> a > c;
*/

/*@
requires a > b && b > c;
ensures \result > c;
*/
int calc_example_12(int a, int b, int c)
{
    // Variable declarations at scope top
    int result;

    //@ assert a > b;
    //@ assert b > c;
    //@ assert a > c;
    
    result = a;
    return result;
}

int main()
{
    return 0;
}
