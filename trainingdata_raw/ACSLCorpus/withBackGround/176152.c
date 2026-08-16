/*@
    logic integer mul(integer x, integer y) = x * y;

    lemma mul_is_monotonic:
        \forall integer x, y;
            0 <= x <= y && y <= 10 && x <= 10 ==>
            mul(x, 10) <= mul(y, 10);
*/

/*@
    requires 0 <= x <= y && y <= 10 && x <= 10;
    ensures \result == 1;
    assigns \nothing;
*/
int example_mul_usage(int x, int y) {
    //@ assert mul(x, 10) <= mul(y, 10);
    return 1;
}

/*@
    assigns \nothing;
*/
int main() {
    int result1;
    int result2;
    int result3;
    
    result1 = example_mul_usage(2, 4);
    //@ assert mul(2, 10) <= mul(4, 10);
    
    result2 = example_mul_usage(3, 5);
    //@ assert mul(3, 10) <= mul(5, 10);
    
    result3 = example_mul_usage(7, 8);
    //@ assert mul(7, 10) <= mul(8, 10);
    
    return 0;
}
