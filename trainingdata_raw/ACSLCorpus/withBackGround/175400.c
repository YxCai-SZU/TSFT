/*@
    predicate bound_condition(integer x, integer y) =
        x <= 8 && y <= 8;

    lemma bound_check: \forall integer x, y; x >= 0 && y >= 0 && bound_condition(x, y) ==> x * y <= 64;
*/

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 10000;
    ensures \result <= 64;
    assigns \nothing;
*/
unsigned int product_within_bounds(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top of scope
    unsigned int product;
    
    //@ assert bound_condition(x, y);
    //@ assert x * y <= 64;
    
    product = x * y;
    
    return product;
}

/*@ assigns \nothing; */
int main(void)
{
    return 0;
}
