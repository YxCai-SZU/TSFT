/*@
    predicate valid_range(integer a) = 1 <= a && a <= 100;
    
    logic integer square(integer a) = a * a;
    
    lemma square_bound: \forall integer a; valid_range(a) ==> square(a) <= 10000;
*/

/*@
    requires valid_range(a);
    ensures \result == square(a);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert 1 <= a;
    //@ assert a <= 100;
    //@ assert a * a <= 10000;
    
    result = a * a;
    
    return result;
}
