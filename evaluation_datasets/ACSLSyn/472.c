#include <stdbool.h>
#include <stdint.h>

/*@
    predicate pos_lt(integer a, integer b) = a > 0 && b > 0 && a < b;
*/

/*@
    lemma example_6: \forall integer a, b; pos_lt(a, b) ==> a / b <= 1 && a / b >= 0;
    lemma example_7: \forall integer a, b; pos_lt(a, b) ==> a % b == a - (a / b) * b;
    lemma example_8: \forall integer a, b; pos_lt(a, b) ==> a - (a / b) * b >= 0;
    lemma example_9: \forall integer a, b; pos_lt(a, b) ==> a - (a / b) * b < b;
*/

/*@
    predicate truncate_u16(integer n, integer result) =
        result == (n & 0xFFFF);

    lemma truncate_properties:
        \forall integer a;
            truncate_u16(a, (unsigned short)(a & 0xFFFF));

    lemma test_truncation:
        \forall integer a;
            0 <= a <= 0xFFFFFFFF ==>
            truncate_u16(a, (unsigned short)(a & 0xFFFF));

    lemma test_left_shift_u32_vs_u64:
        \forall integer y;
            0 <= y < 32 ==>
            (unsigned int)(1U << y) == (unsigned long long)(1ULL << y);
*/

unsigned short truncate_u16(unsigned int n) {
    //@ assert n <= 0xFFFFFFFF;
    unsigned short result;
    result = (unsigned short)n;
    //@ assert result == (unsigned short)(n & 0xFFFF);
    return result;
}

unsigned short compute_and_truncate(unsigned int a, unsigned int b) {
    int div_result;
    unsigned short truncated;

    //@ assert pos_lt(a, b);
    div_result = a / b;
    //@ assert div_result <= 1;
    //@ assert div_result >= 0;

    truncated = truncate_u16((unsigned int)div_result);
    //@ assert truncated == (unsigned short)(div_result & 0xFFFF);
    //@ assert truncated == (unsigned short)((a / b) & 0xFFFF);

    return truncated;
}

unsigned short process_ratio(unsigned int a, unsigned int b) {
    unsigned short ratio_truncated;
    
    //@ assert pos_lt(a, b);
    
    ratio_truncated = compute_and_truncate(a, b);
    
    //@ assert ratio_truncated == (unsigned short)((a / b) & 0xFFFF);
    //@ assert ratio_truncated <= 1;
    
    return ratio_truncated;
}

int main() {
    unsigned int a = 5;
    unsigned int b = 10;
    unsigned short result;
    
    //@ assert pos_lt(a, b);
    
    result = process_ratio(a, b);
    
    //@ assert result == (unsigned short)((a / b) & 0xFFFF);
    //@ assert result <= 1;
    
    return 0;
}
