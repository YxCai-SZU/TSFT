#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/* ========== Original functions (unchanged) ========== */

/* --- Function 1: Check if three values are strictly increasing --- */
/*@ predicate is_valid_range(integer v) = 1 <= v <= 100; */
/*@ predicate is_strictly_increasing(integer a, integer b, integer c) = a < b && b < c; */
/*@ lemma trivial_implication: \forall integer a, b, c;
      is_strictly_increasing(a, b, c) ==> is_strictly_increasing(a, b, c); */
bool func1(const unsigned int s[3]) {
    bool result;
    //@ assert is_valid_range(s[0]);
    //@ assert is_valid_range(s[1]);
    //@ assert is_valid_range(s[2]);
    result = (s[0] < s[1]) && (s[1] < s[2]);
    return result;
}

/* --- Function 2: Weighted sum comparison --- */
/*@ predicate valid_range(integer x) = 1 <= x <= 100; */
/*@ logic integer weighted_sum(integer a) = a * 2 + (100 - a) * 1; */
/*@ lemma sum_formula: \forall integer a; weighted_sum(a) == a * 2 + (100 - a) * 1; */
bool func2(unsigned int a, unsigned int b) {
    unsigned int a_cnt;
    unsigned int b_cnt;
    unsigned int sum_cnt;
    bool result;
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    a_cnt = a * 2;
    b_cnt = (100 - a) * 1;
    sum_cnt = a_cnt + b_cnt;
    //@ assert sum_cnt == weighted_sum(a);
    result = (sum_cnt / 2 >= b);
    //@ assert result == (weighted_sum(a) / 2 >= b);
    return result;
}

/* --- Function 3: Adjust value based on conditions --- */
/*@ predicate valid_input(integer a, integer b, integer c, integer k) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100 && 1 <= k <= 3; */
/*@ logic integer final_result(integer a, integer cnt) = a + cnt; */
/*@ lemma cnt_range:
        \forall integer a, b, c, k, cnt;
        valid_input(a, b, c, k) && (cnt == 1 || cnt == -1 || cnt == 0 || cnt == 2) ==>
        (final_result(a, cnt) == a || final_result(a, cnt) == a - 1 ||
         final_result(a, cnt) == a + 1 || final_result(a, cnt) == a + 2); */
int func3(int a, int b, int c, int k) {
    int ans = a;
    int cnt = 0;
    int k_copy = k;
    if (k_copy >= 1) {
        cnt += 1;
        k_copy -= 1;
    }
    if (k_copy >= 1 && b >= 1) {
        cnt -= 1;
        k_copy -= 1;
    }
    if (k_copy >= 1 && c >= 1) {
        cnt += 1;
        k_copy -= 1;
    }
    //@ assert cnt == 1 || cnt == -1 || cnt == 0 || cnt == 2;
    //@ assert ans + cnt == a + 1 || ans + cnt == a - 1 || ans + cnt == a + 2 || ans + cnt == a;
    ans += cnt;
    return ans;
}

/* --- Function 4: Compute cube of floor division by 3 --- */
/*@ predicate is_valid_input(integer l) = 1 <= l && l <= 1000; */
/*@ logic integer expected_result(integer l) = (l / 3) * (l / 3) * (l / 3); */
/*@ lemma division_bound: \forall integer l; is_valid_input(l) ==> l / 3 <= 333; */
/*@ lemma square_bound: \forall integer l; is_valid_input(l) ==> (l / 3) * (l / 3) <= 333 * 333; */
/*@ lemma cube_bound: \forall integer l; is_valid_input(l) ==> (l / 3) * (l / 3) * (l / 3) <= 333 * 333 * 333; */
int64_t func4(int64_t l) {
    uint64_t l_unsigned;
    uint64_t ans;
    int64_t ret;
    //@ assert l >= 1 && l <= 1000;
    if (l < 0) {
        l_unsigned = (uint64_t)(-l);
    } else {
        l_unsigned = (uint64_t)l;
    }
    //@ assert l_unsigned <= 1000;
    //@ assert l_unsigned / 3 <= 333;
    //@ assert (l_unsigned / 3) * (l_unsigned / 3) <= 333 * 333;
    //@ assert (l_unsigned / 3) * (l_unsigned / 3) * (l_unsigned / 3) <= 333 * 333 * 333;
    ans = (l_unsigned / 3) * (l_unsigned / 3) * (l_unsigned / 3);
    if (l < 0) {
        ret = -1;
        //@ assert ret == -1;
    } else {
        ret = (int64_t)ans;
        //@ assert ret == (int64_t)ans;
    }
    return ret;
}


/* ========== Synthesized scenario: Resource allocation and validation ========== */

/*@
    predicate valid_resource_params(integer x, integer y, integer z, integer k, integer l) =
        is_valid_range((integer)x) && is_valid_range((integer)y) && is_valid_range((integer)z) &&
        valid_range((unsigned int)x) && valid_range((unsigned int)y) &&
        0 <= x <= 100 && 0 <= y <= 100 && 0 <= z <= 100 && 1 <= k <= 3 &&
        is_valid_input(l);

    predicate valid_allocation(integer adjusted_val, integer original_val, int64_t volume) =
        (adjusted_val == original_val || adjusted_val == original_val - 1 ||
         adjusted_val == original_val + 1 || adjusted_val == original_val + 2) &&
        (volume >= 0 && volume <= 333 * 333 * 333);
*/

struct AllocationResult {
    int adjusted;
    int64_t volume;
    bool is_increasing;
    bool weight_ok;
};

struct AllocationResult synthesized_func(int x, int y, int z, int k, int64_t l) {
    struct AllocationResult res;
    unsigned int input_array[3] = {(unsigned int)x, (unsigned int)y, (unsigned int)z};
    
    bool inc = func1(input_array);
    res.is_increasing = inc;
    
    bool weight_ok = func2((unsigned int)x, (unsigned int)y);
    res.weight_ok = weight_ok;
    
    int adjusted = func3(x, y, z, k);
    res.adjusted = adjusted;
    
    int64_t volume = func4(l);
    res.volume = volume;
    
    //@ assert valid_allocation(res.adjusted, x, res.volume);
    
    return res;
}
