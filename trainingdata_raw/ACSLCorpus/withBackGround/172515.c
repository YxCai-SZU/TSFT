/*@
    predicate x_in_range(integer x) = -1290 <= x && x <= 1290;
    
    logic integer cube(integer x) = x * x * x;
    
    lemma square_bounds:
        \forall integer x; x_in_range(x) ==> -1290*1290 <= x*x && x*x <= 1290*1290;
    
    lemma cube_bounds:
        \forall integer x; x_in_range(x) ==> -1290*1290*1290 <= x*x*x && x*x*x <= 1290*1290*1290;
*/

/*@
    requires x_in_range(x);
    ensures \result == cube(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert x_in_range(x);
    //@ assert -1290*1290 <= x*x && x*x <= 1290*1290;
    //@ assert -1290*1290*1290 <= x*x*x && x*x*x <= 1290*1290*1290;
    
    result = x * x * x;
    
    //@ assert result == cube(x);
    return result;
}
