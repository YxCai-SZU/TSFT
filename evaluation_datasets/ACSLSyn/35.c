#include <stdbool.h>

/*@
    predicate is_valid_range(integer a0, integer a1) =
        1 <= a0 && a0 <= 12 &&
        1 <= a1 && a1 <= 31;

    logic integer compute_ans(integer a0, integer a1) =
        a0 <= a1 ?
            a0 + (a1 - a0) * 2 :
            a1 + (a0 - a1) * 2;

    lemma ans_nonnegative:
        \forall integer a0, a1;
            is_valid_range(a0, a1) ==> compute_ans(a0, a1) >= 0;

    lemma final_result_nonnegative:
        \forall integer a0, a1;
            is_valid_range(a0, a1) ==> compute_ans(a0, a1) - 1 >= 0;
*/

int func(int a[2]) {
    int ans;
    int tmp0;
    int tmp1;
    
    tmp0 = a[0];
    tmp1 = a[1];
    
    //@ assert is_valid_range(tmp0, tmp1);
    
    if (tmp0 <= tmp1) {
        ans = tmp0 + (tmp1 - tmp0) * 2;
    } else {
        ans = tmp1 + (tmp0 - tmp1) * 2;
    }
    
    //@ assert ans == compute_ans(tmp0, tmp1);
    //@ assert ans >= 0;
    
    ans = ans - 1;
    
    //@ assert ans >= 0;
    
    return ans;
}

int example_proof() {
    int result;
    result = 2 * 3;
    return result;
}

int calculate_discount(int date[2]) {
    int base_discount;
    int scaling_factor;
    int final_discount;

    base_discount = func(date);
    //@ assert base_discount >= 0;

    scaling_factor = example_proof();
    //@ assert scaling_factor == 6;

    final_discount = base_discount * scaling_factor;

    //@ assert final_discount % 6 == 0;

    return final_discount;
}
