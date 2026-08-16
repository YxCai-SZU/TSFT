/*@
    predicate bounds(integer x, integer y, integer z) =
        x <= 5 && y <= 7 && z <= 10;

    logic integer multiply_add(integer x, integer y, integer z) =
        x * y + z;

    lemma multiplication_bound1:
        \forall integer x, y; 0 <= x <= 5 && 0 <= y <= 7 ==> x * y <= 35;

    lemma multiplication_bound2:
        \forall integer x, y; 0 <= x <= 5 && 0 <= y <= 7 ==> x * y <= 35;

    lemma multiplication_bound3:
        \forall integer x, y; 0 <= x <= 5 && 0 <= y <= 7 ==> x * y <= 100;

    lemma addition_bound:
        \forall integer x, y, z; 0 <= x <= 5 && 0 <= y <= 7 && 0 <= z <= 10 ==> 
            x * y + z <= 100 + z;

    lemma final_bound:
        \forall integer x, y, z; 0 <= x <= 5 && 0 <= y <= 7 && 0 <= z <= 10 ==> 
            x * y + z <= 110;
*/

/*@
    requires 0 <= x <= 5 && 0 <= y <= 7 && 0 <= z <= 10;
    ensures \result == x * y + z;
    assigns \nothing;
*/
unsigned int func(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x * y <= 35;
    //@ assert x * y <= 100;
    //@ assert x * y + z <= 100 + z;
    //@ assert x * y + z <= 110;
    
    return x * y + z;
}
