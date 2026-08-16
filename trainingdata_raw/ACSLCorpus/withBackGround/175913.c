/*@
    predicate valid_input(integer x) = 1 <= x && x <= 10;
    
    logic integer triple_triple(integer x) = x * 3 * 3;
    
    lemma no_overflow1: \forall integer x; valid_input(x) ==> x * 3 <= 30;
    lemma no_overflow2: \forall integer x; valid_input(x) ==> x * 3 * 3 <= 90;
*/

/*@
    requires valid_input(input);
    ensures \result == triple_triple(input);
    assigns \nothing;
*/
int func(int input)
{
    int result;
    
    //@ assert valid_input(input);
    //@ assert input * 3 <= 30;
    //@ assert input * 3 * 3 <= 90;
    
    result = input * 3 * 3;
    
    //@ assert result == triple_triple(input);
    return result;
}
