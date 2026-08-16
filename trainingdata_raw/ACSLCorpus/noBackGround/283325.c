/*@
    requires 0 <= x <= 8;
    requires 0 <= y <= 8;
    requires 0 <= z <= 8;
    ensures \result == x * y + x * z;
    assigns \nothing;
*/
int compute_distributive(int x, int y, int z) {
    int result;
    int temp_sum;
    int left_product;
    int right_product;

    //@ assert (0 <= (x) <= 8) && (0 <= (y) <= 8) && (0 <= (z) <= 8);
    temp_sum = y + z;
    left_product = x * temp_sum;
    right_product = x * y + x * z;
    
    //@ assert left_product == right_product;
    result = right_product;
    return result;
}
