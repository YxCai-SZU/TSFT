#include <stdbool.h>
#include <stdint.h>

/* ===== Function 1: compute even pairs ===== */
/*@
    predicate valid_params(integer A, integer B) =
        1 <= A && A <= 100 &&
        1 <= B && B <= 100;

    logic integer func_result(integer A, integer B) =
        A < 2 ? 0 : (B * 2 > A ? A - (A % 2) : B * 2);

    lemma result_bounds:
        \forall integer A, B;
        valid_params(A, B) ==>
        func_result(A, B) <= A &&
        func_result(A, B) >= 0;
*/

unsigned int func_even_pairs(unsigned int A, unsigned int B) {
    unsigned int ans = 0;
    unsigned int i = 0;

    while (i < B) {
        if (ans + 2 <= A) {
            ans += 2;
        } else {
            break;
        }
        i += 1;
    }

    //@ assert ans <= A;
    return ans;
}

/* ===== Function 2: majority vote (at least 2 out of 3) ===== */
/*@ predicate is_zero_or_one(integer x) = x == 0 || x == 1; */

/*@ predicate vector_valid(int *v, integer len) =
    len == 3 &&
    \forall integer i; 0 <= i < len ==> is_zero_or_one(v[i]); */

/*@ predicate result_condition(int *v, integer len, bool result) =
    result == (
        (v[1] == 1 && v[2] == 1) ||
        (v[0] == 1 && v[2] == 1) ||
        (v[0] == 1 && v[1] == 1)
    ); */

bool func_majority(int *v) {
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    if (a == 1 && b == 1) {
        result = true;
        //@ assert result_condition(v, 3, result);
        return result;
    } else if (b == 1 && c == 1) {
        result = true;
        //@ assert result_condition(v, 3, result);
        return result;
    } else if (a == 1 && c == 1) {
        result = true;
        //@ assert result_condition(v, 3, result);
        return result;
    }

    //@ assert a == 0 || b == 0 || c == 0;
    result = false;
    //@ assert result_condition(v, 3, result);
    return result;
}

/* ===== Function 3: check if one number is sum of other two ===== */
/*@ predicate valid_triplet(integer a, integer b, integer c) =
      a >= 1 && a <= 100 &&
      b >= 1 && b <= 100 &&
      c >= 1 && c <= 100;
*/

/*@ logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ca(integer c, integer a) = c + a;
*/

/*@ lemma sum_equivalence:
      \forall integer a,b,c;
        valid_triplet(a,b,c) ==>
        (sum_ab(a,b) == c || sum_bc(b,c) == a || sum_ca(c,a) == b) ==>
        (a + b == c || b + c == a || c + a == b);
*/

bool func_sum_check(const unsigned int* v) {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int sum1;
    unsigned int sum2;
    unsigned int sum3;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert valid_triplet(a,b,c);

    sum1 = a + b;
    sum2 = b + c;
    sum3 = c + a;

    if (sum1 == c || sum2 == a || sum3 == b) {
        result = true;
    } else {
        //@ assert sum1 != c && sum2 != a && sum3 != b;
        result = false;
    }

    return result;
}

/* ===== Function 4: modulo 4 check ===== */
/*@ predicate is_valid_range(integer n, integer m) =
      1 <= n && n <= 100 &&
      1 <= m && m <= 100;
*/

/*@ logic integer compute_expr(integer n, integer m) =
      (n * 2 + m * 1) % 4;
*/

/*@ lemma result_range:
      \forall integer n, m;
      is_valid_range(n, m) ==>
      0 <= compute_expr(n, m) && compute_expr(n, m) <= 3;
*/

int32_t func_mod_check(uint32_t n, uint32_t m)
{
    int32_t result;
    
    //@ assert is_valid_range(n, m);
    
    if (((n * 2 + m * 1) % 4) == 0) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 1 || result == 0;
    return result;
}

/* ===== Synthesized complex function: Data validation pipeline ===== */
int32_t synthesized_func(unsigned int A, unsigned int B, int *v, const unsigned int *w, uint32_t n, uint32_t m)
{
    unsigned int max_even;
    bool majority;
    bool is_sum;
    int32_t mod_flag;
    int32_t result;

    max_even = func_even_pairs(A, B);
    //@ assert max_even <= A;

    majority = func_majority(v);
    //@ assert result_condition(v, 3, majority);

    is_sum = func_sum_check(w);
    //@ assert is_sum == (w[0] + w[1] == w[2] || w[1] + w[2] == w[0] || w[2] + w[0] == w[1]);

    mod_flag = func_mod_check(n, m);
    //@ assert mod_flag == 1 || mod_flag == 0;

    if (max_even > 0 && majority && is_sum && mod_flag == 1) {
        result = 1;
    } else {
        result = 0;
    }

    //@ assert (result == 1) <==> (max_even > 0 && majority && is_sum && mod_flag == 1);
    return result;
}
