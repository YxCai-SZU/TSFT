#include <stdbool.h>
#include <stddef.h>

/*@
    predicate le(integer a, integer b) = a <= b;

    lemma transitivity:
        \forall integer a, b, c;
            le(a, b) && le(b, c) ==> le(a, c);

    lemma add_to_transitivity_fixed:
        \forall integer a, b, c, k;
            le(a, b) && le(b, c) ==> le(a + k, c + k);
*/

int lemma_transitivity(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 0;
}

int lemma_add_to_transitivity(int a, int b, int c) {
    int k;
    int result;

    k = 3;
    result = lemma_transitivity(a, b, c);
    //@ assert a + k <= c + k;
    return 0;
}

int lemma_add_to_transitivity_fixed(int a, int b, int c, int k) {
    int result;

    result = lemma_transitivity(a, b, c);
    //@ assert a + k <= b + k;
    //@ assert b + k <= c + k;
    result = lemma_transitivity(a + k, b + k, c + k);
    return 0;
}

/* ========== ORIGINAL FUNCTION 2: Array processing ========== */

/*@ predicate valid_array(int *arr, size_t len, size_t N) =
      len == N &&
      N >= 1 && N <= 200000 &&
      \forall size_t i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= (int)N;
*/

/*@ lemma ans_bounds:
      \forall size_t N, int ans;
      N >= 1 && N <= 200000 && ans >= 0 && ans <= (int)N ==> ans <= (int)N;
*/

int func_array(size_t N, const int *A) {
    int ans = 0;
    int cnt = 0;
    size_t index = 0;
    
    while (index < N) {
        int a = A[index];
        //@ assert a >= 1 && a <= (int)N;
        if (cnt == a - 1) {
            ans += 1;
            cnt = 0;
        } else {
            cnt += 1;
        }
        index += 1;
    }
    return ans;
}

/* ========== ORIGINAL FUNCTION 3: Vector validation ========== */

/*@ predicate valid_vec(int *v) = 
      \valid(v) && \valid(v+1) && \valid(v+2) &&
      v[0] >= 1 && v[0] <= 100 &&
      v[1] >= 1 && v[1] <= 100 &&
      v[2] >= 1 && v[2] <= 200;
*/

/*@ logic integer sum_bounds(integer a, integer b) = a + b; */

/*@ lemma sum_range: 
      \forall integer a, b; 
      (a >= 1 && a <= 100 && b >= 1 && b <= 100) ==> 
      (sum_bounds(a, b) >= 1 && sum_bounds(a, b) <= 200);
*/

bool func_vec(int *v) {
    int a;
    int b;
    int c;
    bool result;
    int sum;
    
    a = v[0];
    b = v[1];
    c = v[2];
    result = false;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 200;
    
    //@ assert sum_bounds(a, b) >= 1 && sum_bounds(a, b) <= 200;
    sum = a + b;
    
    if (c <= sum) {
        result = true;
    }
    
    //@ assert result == (c <= sum);
    return result;
}

/* ========== ORIGINAL FUNCTION 4: Counting within bounds ========== */

/*@ predicate valid_params(integer N, integer K, int *X) =
      N >= 1 && N <= 100 &&
      K >= 1 && K <= 1000000 &&
      \valid(X + (0 .. N-1)) &&
      \forall integer j; 0 <= j < N ==> X[j] >= 1 && X[j] <= 1000000;
*/

/*@ predicate ans_bounds(integer ans, integer N) =
      ans >= 0 && ans <= N;
*/

/*@ lemma ans_monotonic:
      \forall integer i, ans, N, K, int *X;
      valid_params(N, K, X) && 0 <= i <= N && 0 <= ans <= i ==>
      ans <= N;
*/

int func_count(int N, int K, int *X) {
    int ans = 0;
    int i = 0;
    
    while (i < N) {
        //@ assert 0 <= i < N;
        if (K - X[i] >= 0) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}

bool process_and_validate(int N, int K, int *X, int *v) {
    int ans_count;
    bool vec_result;
    
    ans_count = func_count(N, K, X);
    
    vec_result = func_vec(v);
    
    //@ assert ans_count >= 0 && ans_count <= N;
    
    //@ assert vec_result == (v[2] <= v[0] + v[1]);
    
    return vec_result;
}
