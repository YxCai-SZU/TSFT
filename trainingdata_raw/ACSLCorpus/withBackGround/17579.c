#include <stdint.h>

/*@
    predicate le_8(integer x) = x <= 8;
    predicate le_10(integer x) = x <= 10;
    predicate le_16(integer x) = x <= 16;
    predicate le_20(integer x) = x <= 20;
    predicate le_64(integer x) = x <= 64;
    predicate le_100(integer x) = x <= 100;
    predicate le_256(integer x) = x <= 256;
    predicate le_400(integer x) = x <= 400;
    predicate le_1000(integer x) = x <= 1000;
*/

/*@
    predicate mul_le_64(integer x, integer y) = x * y <= 64;
    predicate mul_le_100(integer x, integer y) = x * y <= 100;
    predicate mul_le_256(integer x, integer y) = x * y <= 256;
    predicate mul_le_400(integer x, integer y) = x * y <= 400;
*/

/*@
    lemma nonlinear_arithmetic_example:
        \forall integer x, y; 0 <= x <= 8 && 0 <= y <= 8 ==> mul_le_64(x, y);
    
    lemma bound_check:
        \forall integer x, y; 0 <= x <= 8 && 0 <= y <= 8 ==> le_1000(x * y);
    
    lemma nonlinear_arithmetic_example2:
        \forall integer x, y; 0 <= x <= 10 && 0 <= y <= 10 ==> mul_le_100(x, y);
    
    lemma bound_check2:
        \forall integer x, y; 0 <= x <= 10 && 0 <= y <= 10 ==> le_1000(x * y);
    
    lemma nonlinear_arithmetic_example3:
        \forall integer x, y; 0 <= x <= 16 && 0 <= y <= 16 ==> mul_le_256(x, y);
    
    lemma bound_check3:
        \forall integer x, y; 0 <= x <= 16 && 0 <= y <= 16 ==> le_1000(x * y);
    
    lemma nonlinear_arithmetic_example4:
        \forall integer x, y; 0 <= x <= 20 && 0 <= y <= 20 ==> mul_le_400(x, y);
    
    lemma bound_check4:
        \forall integer x, y; 0 <= x <= 20 && 0 <= y <= 20 ==> le_1000(x * y);
*/

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8;
    ensures le_1000(x * y);
    assigns \nothing;
*/
void bound_check_c(uint32_t x, uint32_t y)
{
    //@ assert mul_le_64(x, y);
}

/*@
    requires 0 <= x <= 10 && 0 <= y <= 10;
    ensures le_1000(x * y);
    assigns \nothing;
*/
void bound_check2_c(uint32_t x, uint32_t y)
{
    //@ assert mul_le_100(x, y);
}

/*@
    requires 0 <= x <= 16 && 0 <= y <= 16;
    ensures le_1000(x * y);
    assigns \nothing;
*/
void bound_check3_c(uint32_t x, uint32_t y)
{
    //@ assert mul_le_256(x, y);
}

/*@
    requires 0 <= x <= 20 && 0 <= y <= 20;
    ensures le_1000(x * y);
    assigns \nothing;
*/
void bound_check4_c(uint32_t x, uint32_t y)
{
    //@ assert mul_le_400(x, y);
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
