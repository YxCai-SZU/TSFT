/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 10;
    
    logic integer cube(integer x) = x * x * x;
    
    lemma cube_range:
        \forall integer x; is_valid_range(x) ==> 1 <= cube(x) && cube(x) <= 1000;
*/

/*@
    requires is_valid_range(x);
    ensures \result == cube(x) + 0x3F800000;
    assigns \nothing;
*/
unsigned int func(unsigned int x)
{
    unsigned int cube;
    unsigned int result;
    
    //@ assert is_valid_range(x);
    
    //@ assert 1 <= x * x && x * x <= 100;
    //@ assert 1 <= x * x * x && x * x * x <= 1000;
    
    cube = x * x * x;
    result = cube + 0x3F800000;
    
    //@ assert result == cube(x) + 0x3F800000;
    return result;
}
