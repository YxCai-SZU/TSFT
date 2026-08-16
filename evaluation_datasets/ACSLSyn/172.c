#include <stdbool.h>

/* First function: checks if two arrays have matching difference patterns */
/*@ predicate valid_index(integer i) = 0 <= i < 3;
    predicate valid_value(integer v) = 1 <= v <= 13;
    predicate valid_array(int *arr) = 
        \forall integer i; valid_index(i) ==> valid_value(arr[i]);
    predicate same_diffs(int *A, int *B) = 
        A[1] - A[0] == B[2] - B[1] && A[2] - A[1] == B[1] - B[0];
*/

bool check_diff_pattern(int *A, int *B) {
    //@ assert valid_array(A);
    //@ assert valid_array(B);
    //@ assert valid_index(0);
    //@ assert valid_index(1);
    //@ assert valid_index(2);
    //@ assert valid_value(A[0]);
    //@ assert valid_value(A[1]);
    //@ assert valid_value(A[2]);
    //@ assert valid_value(B[0]);
    //@ assert valid_value(B[1]);
    //@ assert valid_value(B[2]);
    
    return (A[1] - A[0] == B[2] - B[1] && A[2] - A[1] == B[1] - B[0]);
}

/* Second function: checks if product of doubled values exceeds square of n */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 100000;
    predicate b_in_range(integer b) = 1 <= b <= 100000;
    predicate n_in_range(integer n) = 1 <= n <= 100000;
    
    logic integer double_a(integer a) = a * 2;
    logic integer double_b(integer b) = b * 2;
    logic integer square_n(integer n) = n * n;
    
    lemma double_a_bound: \forall integer a; a_in_range(a) ==> double_a(a) <= 200000;
    lemma double_b_bound: \forall integer b; b_in_range(b) ==> double_b(b) <= 200000;
    lemma product_bound: \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> 
        double_a(a) * double_b(b) <= 40000000000;
    lemma square_bound: \forall integer n; n_in_range(n) ==> square_n(n) <= 10000000000;
*/

bool check_doubled_product_exceeds_square(unsigned long n, unsigned long a, unsigned long b)
{
    unsigned long na;
    unsigned long nb;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert n_in_range(n);
    
    na = n / a;
    nb = n / b;
    
    //@ assert na <= 100000;
    //@ assert nb <= 100000;
    
    //@ assert double_a(a) <= 200000;
    //@ assert double_b(b) <= 200000;
    
    //@ assert double_a(a) * double_b(b) <= 40000000000;
    //@ assert square_n(n) <= 10000000000;
    
    return a * 2 * b * 2 > n * n;
}

/* Synthesized function: 
   Scenario: In a cryptographic key generation system, we need to verify that 
   two candidate key arrays have a valid difference pattern AND that the 
   combined entropy parameters exceed a threshold for security.
   
   Data flow: Given two arrays A and B representing key components, and 
   parameters n, a, b representing entropy scaling factors, we first check 
   if the arrays have a valid difference pattern (ensuring structural 
   compatibility), then verify that the product of doubled scaling factors 
   exceeds the square of n (ensuring sufficient entropy). The final assertion 
   captures the combined security property: the arrays are structurally 
   compatible AND the entropy is sufficient.
*/

bool validate_key_components(int *A, int *B, unsigned long n, unsigned long a, unsigned long b)
{
    bool pattern_ok = check_diff_pattern(A, B);
    bool entropy_ok = check_doubled_product_exceeds_square(n, a, b);
    bool result = pattern_ok && entropy_ok;
    
    //@ assert (same_diffs(A, B) && (a * 2 * b * 2 > n * n)) ==> result;
    //@ assert !(same_diffs(A, B) && (a * 2 * b * 2 > n * n)) ==> !result;
    
    return result;
}
