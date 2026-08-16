#include <stdbool.h>
#include <stdint.h>

/* ===== First snippet functions ===== */

/*@ predicate is_multiple_of_3(integer n) = n % 3 == 0; */
/*@ predicate is_multiple_of_5(integer n) = n % 5 == 0; */

bool is_multiple_of_3_c(unsigned int n) {
    bool res;
    res = (n % 3 == 0);
    //@ assert res == (n % 3 == 0);
    return res;
}

bool is_multiple_of_5_c(unsigned int n) {
    bool res;
    res = (n % 5 == 0);
    //@ assert res == (n % 5 == 0);
    return res;
}

unsigned int func1(unsigned int r) {
    unsigned int res;
    if (r % 3 == 0 || r % 5 == 0) {
        res = 0;
    } else {
        res = 3 * r;
    }
    //@ assert res <= 3 * r;
    return res;
}

unsigned int func2(unsigned int r) {
    unsigned int res;
    //@ assert 1 <= r && r <= 100;
    res = r * r * 3;
    //@ assert res == r * r * 3;
    return res;
}

/* ===== Second snippet functions ===== */

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 &&
        k >= 1 && k <= a + b + c && k <= 2000000000;
*/

/*@
    logic integer func_result(integer a, integer b, integer c, integer k) =
        k >= a ? a : (k > 0 ? k - (k - a) : 0);
*/

/*@
    lemma result_bound: \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==> func_result(a, b, c, k) <= a;
*/

int32_t func3(int32_t a, int32_t b, int32_t c, int32_t k) {
    int32_t a_cnt;
    int32_t k_cnt;
    
    a_cnt = a;
    k_cnt = k;
    
    //@ assert a_cnt == a && k_cnt == k;
    
    if (k_cnt >= a_cnt) {
        k_cnt = k_cnt - a_cnt;
        //@ assert a_cnt <= a;
        return a_cnt;
    } else {
        a_cnt = k_cnt;
        k_cnt = 0;
    }
    
    //@ assert a_cnt >= 0 && a_cnt <= a;
    
    if (k_cnt > 0) {
        a_cnt = a_cnt - k_cnt;
    }
    
    //@ assert a_cnt <= a;
    //@ assert a_cnt >= 0;
    
    return a_cnt;
}

/* ===== Third snippet functions ===== */

/*@ predicate r_in_bounds(integer r) = 1 <= r && r <= 100; */

/*@ logic integer area(integer r, integer pi) = r * r * pi; */

int32_t func4(uint32_t r)
{
    int32_t pi;
    int32_t res;
    
    //@ assert r_in_bounds(r);
    
    pi = 3;
    
    res = (int32_t)(r * r) * pi;
    
    //@ assert res == area(r, 3);
    
    return res;
}

/* ===== Fourth snippet functions ===== */

/*@ predicate min_val(integer A, integer B, integer m) =
      (A <= B ==> m == A) && (B <= A ==> m == B);
*/

/*@ predicate max_val(integer A, integer B, integer M) =
      (A >= B ==> M == A) && (B >= A ==> M == B);
*/

uint64_t func5(uint64_t X, uint64_t A, uint64_t B) {
    uint64_t min_val;
    uint64_t max_val;

    //@ assert 1 <= A <= 1000;
    //@ assert 1 <= B <= 1000;
    //@ assert A + B <= X <= 10000;

    if (A < B) {
        min_val = A;
        max_val = B;
    } else {
        min_val = B;
        max_val = A;
    }

    //@ assert min_val(A, B, min_val);
    //@ assert max_val(A, B, max_val);
    //@ assert min_val + max_val == A + B;

    if (X - max_val < min_val) {
        //@ assert X - max_val <= X;
        //@ assert X - max_val == X - A || X - max_val == X - B;
        return X - max_val;
    } else {
        //@ assert X - min_val <= X;
        //@ assert X - min_val == X - A || X - min_val == X - B;
        return X - min_val;
    }
}

/* ===== Synthesized complex function: Resource Allocation Verifier ===== */

uint64_t resource_allocator(unsigned int r, uint64_t X, uint64_t A, uint64_t B,
                            int32_t a, int32_t b, int32_t c, int32_t k,
                            unsigned int n) 
{
    uint64_t result;
    uint64_t alloc_size;
    uint64_t min_alloc;
    uint64_t max_alloc;
    unsigned int base_val;
    unsigned int extra_val;
    bool is_multiple_3;
    bool is_multiple_5;
    int32_t limited_val;
    int32_t area_val;
    uint64_t final_alloc;

    base_val = func1(r);
    //@ assert base_val <= 3 * r;

    is_multiple_3 = is_multiple_of_3_c(n);
    is_multiple_5 = is_multiple_of_5_c(n);
    //@ assert is_multiple_3 == (n % 3 == 0);
    //@ assert is_multiple_5 == (n % 5 == 0);

    if (is_multiple_3 && is_multiple_5) {
        extra_val = func2(r);
        //@ assert extra_val == r * r * 3;
    } else {
        extra_val = 0;
    }

    limited_val = func3(a, b, c, k);
    //@ assert limited_val >= 0;
    //@ assert limited_val <= a;

    area_val = func4(r);
    //@ assert area_val == area(r, 3);

    alloc_size = (uint64_t)(base_val + extra_val + limited_val + area_val);
    
    //@ assert A + B <= X;
    if (alloc_size > X) {
        alloc_size = X;
    }

    final_alloc = func5(X, A, B);
    //@ assert final_alloc <= X;
    //@ assert final_alloc == X - A || final_alloc == X - B;

    if (alloc_size < final_alloc) {
        result = alloc_size;
    } else {
        result = final_alloc;
    }

    //@ assert result <= X;
    //@ assert result >= 0;
    
    return result;
}
