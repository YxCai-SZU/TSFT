#include <stdint.h>

/*@
    predicate bounds_ok(integer x, integer y) = x <= 8 && y <= 8;
    predicate product_bound(integer x, integer y) = x * y <= 1000;
    predicate product_bound_small(integer x, integer y) = x * y <= 64;
    predicate mod_identity(integer a, integer b) = b > 0 ==> a % b == a % b;
    predicate distributive_add(integer x, integer y, integer z) = 
        x * (y + z) == x * y + x * z;
*/

/*@
    lemma check_bounds_lemma:
        \forall integer x, y; 0 <= x <= 8 && 0 <= y <= 8 ==> product_bound(x, y);
    lemma check_bounds2_lemma:
        \forall integer x, y; 0 <= x <= 8 && 0 <= y <= 8 ==> product_bound_small(x, y);
    lemma modulo_lemma:
        \forall integer a, b; b > 0 ==> mod_identity(a, b);
    lemma distributive_add_lemma:
        \forall integer x, y, z; 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8 ==> distributive_add(x, y, z);
*/

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8;
    ensures \result <= 1000;
    assigns \nothing;
*/
uint32_t check_bounds(uint32_t x, uint32_t y)
{
    uint32_t product;
    //@ assert 0 <= x <= 8 && 0 <= y <= 8;
    product = x * y;
    
    //@ assert product <= 1000;
    
    return product;
}

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8;
    ensures \result <= 64;
    assigns \nothing;
*/
uint32_t check_bounds2(uint32_t x, uint32_t y)
{
    uint32_t product;
    //@ assert 0 <= x <= 8 && 0 <= y <= 8;
    product = x * y;
    
    //@ assert product <= 64;
    
    return product;
}

/*@
    requires b > 0;
    ensures \result == a % b;
    assigns \nothing;
*/
int modulo_example(int a, int b)
{
    int result;
    //@ assert b > 0;
    result = a % b;
    
    //@ assert result == a % b;
    
    return result;
}

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    ensures \result == x * (y + z);
    ensures \result == x * y + x * z;
    assigns \nothing;
*/
int check_distributive_add(int x, int y, int z)
{
    int left_side;
    int right_side;
    
    //@ assert 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    left_side = x * (y + z);
    right_side = x * y + x * z;
    
    //@ assert left_side == right_side;
    
    return left_side;
}

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    ensures \result == x * (y + z);
    ensures \result == x * y + x * z;
    assigns \nothing;
*/
int lemma_is_distributive_add(int x, int y, int z)
{
    int result;
    //@ assert 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    result = x * (y + z);
    
    //@ assert result == x * y + x * z;
    
    return result;
}

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    ensures \result == x * (y + z);
    ensures \result == x * y + x * z;
    assigns \nothing;
*/
int lemma_is_distributive_add_all_with_conditions(int x, int y, int z)
{
    int result;
    //@ assert 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    result = lemma_is_distributive_add(x, y, z);
    
    //@ assert result == x * y + x * z;
    
    return result;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
