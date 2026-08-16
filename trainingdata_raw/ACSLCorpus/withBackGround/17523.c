/*@
    predicate bounds_xy(integer x, integer y) = x <= 8 && y <= 8;
    predicate product_xy(integer x, integer y) = x * y <= 64;
    
    lemma verify_nonlinear_arith_bounds: \forall integer x, y; 0 <= x <= 8 && 0 <= y <= 8 ==> product_xy(x, y);
    
    predicate bounds_xy_100(integer x, integer y) = x <= 100 && y <= 100;
    predicate product_xy_10000(integer x, integer y) = x * y <= 10000;
    
    lemma verify_product_bounds: \forall integer x, y; 0 <= x <= 100 && 0 <= y <= 100 ==> product_xy_10000(x, y);
    
    predicate bounds_xyz(integer x, integer y, integer z) = x <= 10 && y <= 10 && z <= 10;
    predicate product_sum_xyz(integer x, integer y, integer z) = (x + y) * z <= 200;
    
    lemma verify_product_sum_bounds: \forall integer x, y, z; 0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10 ==> product_sum_xyz(x, y, z);
*/

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 0;
*/
int main() {
    unsigned int x;
    unsigned int y;
    unsigned int z;
    
    //@ assert \true;
    
    return 0;
}
