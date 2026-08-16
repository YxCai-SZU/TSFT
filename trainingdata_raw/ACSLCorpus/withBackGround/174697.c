/*@
    predicate non_linear_arith_example4_pre(integer x, integer a, integer b) =
        x > 0 && a > 0 && b > 0;
    
    predicate non_linear_arith_example4_post(integer x, integer a, integer b) =
        x * (a + b) == x * a + x * b;
    
    lemma non_linear_arith_example4:
        \forall integer x, a, b;
        non_linear_arith_example4_pre(x, a, b) ==>
        non_linear_arith_example4_post(x, a, b);
*/

/*@
    predicate lemma_mul_is_distributive_add_pre(integer x, integer y, integer z) =
        x >= 0 && y >= 0 && z >= 0 &&
        (unsigned int)x * (unsigned int)y <= 4294967295 &&
        (unsigned int)x * (unsigned int)z <= 4294967295 &&
        (unsigned int)x * ((unsigned int)y + (unsigned int)z) <= 4294967295;
    
    predicate lemma_mul_is_distributive_add_post(integer x, integer y, integer z) =
        x * (y + z) == x * y + x * z;
    
    lemma lemma_mul_is_distributive_add:
        \forall integer x, y, z;
        lemma_mul_is_distributive_add_pre(x, y, z) ==>
        lemma_mul_is_distributive_add_post(x, y, z);
*/

/*@
    lemma lemma_mul_is_distributive_add2:
        \forall integer x, y, z;
        lemma_mul_is_distributive_add_pre(x, y, z) ==>
        lemma_mul_is_distributive_add_post(x, y, z);
*/

/*@
    lemma lemma_mul_is_distributive_add3:
        \forall integer x, y, z;
        lemma_mul_is_distributive_add_pre(x, y, z) ==>
        lemma_mul_is_distributive_add_post(x, y, z);
*/

void main() {
    // Empty main function as per original Rust code
}
