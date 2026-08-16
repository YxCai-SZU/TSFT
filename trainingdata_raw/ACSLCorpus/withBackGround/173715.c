/*@
    predicate valid_inputs(integer a, integer p) =
        0 <= a <= 100 && 0 <= p <= 100;
    
    logic integer total(integer a, integer p) = a * 3 + p;
    
    lemma pies_bound:
        \forall integer a, p, pies;
        valid_inputs(a, p) && pies <= total(a, p) / 2 ==> pies <= 200;
*/

/*@
    requires valid_inputs(a, p);
    ensures \result >= 0;
    ensures \result <= total(a, p);
    ensures \result <= 200;
*/
int func(int a, int p)
{
    int total;
    int pies;
    int count;
    
    //@ assert valid_inputs(a, p);
    total = a * 3 + p;
    pies = 0;
    count = total;
    
    /*@
        loop invariant 0 <= pies;
        loop invariant pies <= total / 2;
        loop invariant count == total - 2 * pies;
        loop invariant valid_inputs(a, p);
        loop invariant total == a * 3 + p;
        loop invariant pies <= 200;
        loop assigns pies, count;
    */
    while (count >= 2)
    {
        //@ assert count >= 2;
        count -= 2;
        pies += 1;
        //@ assert pies <= 200;
    }
    
    //@ assert pies <= 200;
    return pies;
}
