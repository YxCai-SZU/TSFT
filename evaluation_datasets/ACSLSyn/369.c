#include <stdint.h>
#include <stdbool.h>

/* ACSL predicates and lemmas from original functions */
/*@
    predicate valid_inputs(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n * n;
    
    logic integer nn_val(integer n) = n * n;
    
    lemma nn_bounded: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    predicate valid_range(integer N, integer M) =
        1 <= N && N <= 20 && 1 <= M && M <= 20;

    logic integer calculate_result(integer N, integer M) =
        (N == M) ? 0 : N * 3;

    lemma result_non_negative:
        \forall integer N, M;
        valid_range(N, M) ==> calculate_result(N, M) >= 0;

    lemma result_cases:
        \forall integer N, M;
        valid_range(N, M) ==>
            (N == M ==> calculate_result(N, M) == 0) &&
            (N != M ==> calculate_result(N, M) == N * 3);
*/

/*@
    predicate is_odd(integer n) = n % 2 != 0;
    
    lemma a_in_range: \forall integer a; 1 <= a <= 10 ==> 
        (a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || 
         a == 6 || a == 7 || a == 8 || a == 9 || a == 10);
*/

/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100;

    logic integer target_result(integer n) = (n / 2) + (n % 2) + 1;

    lemma precondition_holds:
        \forall integer n; is_valid_n(n) ==> 2 <= n && n <= 100;
*/

/* Original function 1: compute n*n - m or -1 */
int32_t func1(uint32_t n, uint32_t m) {
    uint32_t nn;
    int32_t result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= n * n;
    //@ assert n * n <= 10000;
    nn = n * n;
    
    if (nn > m) {
        result = (int32_t)(nn - m);
        //@ assert result >= 0;
        //@ assert result == n * n - m;
        return result;
    } else {
        //@ assert nn <= m;
        return -1;
    }
}

/* Original function 2: compute result based on N and M */
int func2(int N, int M) {
    int result = 0;
    //@ assert valid_range(N, M);
    
    if (N != M) {
        //@ assert N * 3 >= 0;
        //@ assert N * 3 <= 60;
        result = N * 3;
    }
    //@ assert result == calculate_result(N, M);
    return result;
}

/* Original function 3: check if a is 3, 5, or 7 */
bool func3(int a) {
    //@ assert 1 <= a <= 10;
    return a == 7 || a == 5 || a == 3;
}

/* Original function 4: compute (n/2) + (n%2) + 1 */
unsigned int func4(unsigned int n) {
    unsigned int result;
    unsigned int i;
    //@ assert 2 <= n && n <= 100;
    result = (n / 2) + (n % 2) + 1;
    i = 0;
    while (i < n) {
        i = i + 1;
    }
    //@ assert result == target_result(n);
    return result;
}

/* Synthesized function: Network packet validation and processing */
int32_t process_packet(uint32_t n, uint32_t m, int N, int M, int a, unsigned int n2) {
    int32_t result1;
    int result2;
    bool result3;
    unsigned int result4;
    int32_t final_result;
    
    result1 = func1(n, m);
    
    result2 = func2(N, M);
    
    result3 = func3(a);
    
    result4 = func4(n2);
    
    if (result1 >= 0 && result3) {
        final_result = result1 + result2 + (int32_t)result4;
        //@ assert final_result >= 0;
        //@ assert final_result == n * n - m + calculate_result(N, M) + target_result(n2);
        return final_result;
    } else {
        return -1;
    }
}

int main(void) {
    return 0;
}
