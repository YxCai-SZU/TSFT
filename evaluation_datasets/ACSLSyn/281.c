#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>

/* ========== Original Function 1 (with ACSL) ========== */

/*@ predicate is_valid_input(integer a, integer b) =
    a >= 1 && a <= 16 &&
    b >= 1 && b <= 16 &&
    a + b <= 16;
*/

/*@ logic integer max_val(integer a, integer b) =
    a > b ? a : b;
*/

/*@ logic integer min_val(integer a, integer b) =
    a < b ? a : b;
*/

/*@ lemma max_val_property:
    \forall integer a, b;
    max_val(a, b) == a || max_val(a, b) == b;
*/

/*@ lemma min_val_property:
    \forall integer a, b;
    min_val(a, b) == a || min_val(a, b) == b;
*/

bool func1(const unsigned int* input) {
    unsigned int a;
    unsigned int b;
    unsigned int max_val;
    unsigned int min_val;
    bool result;
    
    a = input[0];
    b = input[1];
    
    //@ assert is_valid_input(a, b);
    
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    
    //@ assert max_val == max_val(a, b);
    
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    
    //@ assert min_val == min_val(a, b);
    
    //@ assert max_val == a || max_val == b;
    //@ assert min_val == a || min_val == b;
    
    if (max_val <= 8 || min_val <= 8) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (a <= 8 || b <= 8);
    return result;
}

/* ========== Original Function 2 (with ACSL) ========== */

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer min(integer x, integer y) = x < y ? x : y;
    
    lemma sum_bounds:
        \forall integer a, b, c, d;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
        a + b + c + d <= 40000;
*/

long func2(long a, long b, long c, long d)
{
    long min_ab;
    long min_cd;
    long ans;
    
    //@ assert a >= 1;
    //@ assert b >= 1;
    //@ assert c >= 1;
    //@ assert d >= 1;
    
    //@ assert a <= 10000;
    //@ assert b <= 10000;
    //@ assert c <= 10000;
    //@ assert d <= 10000;
    
    //@ assert a + b + c + d <= 40000;
    
    if (a + b < c) {
        min_ab = a + b;
    } else {
        min_ab = c;
    }
    
    if (c + d < b) {
        min_cd = c + d;
    } else {
        min_cd = b;
    }
    
    if (min_ab < min_cd) {
        ans = min_ab;
    } else {
        ans = min_cd;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= b + c + d;
    
    return ans;
}

/* ========== Original Function 3 (with ACSL) ========== */

/*@
    predicate valid_n(integer n) = 2 <= n <= 100000;

    predicate valid_aa(integer n, int *aa, integer len) =
        len == n - 1 &&
        \forall integer i; 0 <= i < len ==> 
            aa[i] > 1 && aa[i] < n && aa[i] < i + 2;

    predicate an_init(integer n, int *an, integer len) =
        len == n &&
        \forall integer k; 0 <= k < len ==> an[k] == 0;

    predicate an_bounded(integer n, int *an, integer len, integer idx) =
        len == n &&
        \forall integer k; 0 <= k < len ==> 
            an[k] >= 0 && an[k] <= idx;

    lemma an_bounded_lemma:
        \forall integer n, int *an, integer len, integer idx;
            an_init(n, an, len) && 0 <= idx ==> an_bounded(n, an, len, idx);
*/

int func3(int n, int *aa, int *an) {
    int i = 0;
    int index = 0;
    int maxv = 0;
    
    while (i < n) {
        an[i] = 0;
        i = i + 1;
    }
    
    while (index < n-1) {
        int a = aa[index];
        int pos = a - 1;
        
        //@ assert 0 <= pos < n;
        int current_value = an[pos];
        an[pos] = current_value + 1;
        index = index + 1;
    }
    
    i = 0;
    while (i < n) {
        int ai = an[i];
        if (maxv < ai) {
            maxv = ai;
        }
        i = i + 1;
    }
    
    if (maxv == 0) {
        return -1;
    } else {
        return n - maxv;
    }
}

/* ========== Synthesized Complex Function ========== */

/* Scenario: 
   In a network packet scheduling system, we have a resource allocator that:
   1. First checks if a pair of resource IDs (a, b) are valid and small enough (func1)
   2. Then computes a scheduling weight based on four queue lengths (func2)
   3. Finally determines the packet processing order using an array-based counting algorithm (func3)
   
   The combined function simulates a complete resource allocation and scheduling decision.
*/

int scheduling_system(const unsigned int* input, long a, long b, long c, long d, 
                      int n, int *aa, int *an) 
{
    bool resource_valid = func1(input);
    
    long weight = func2(a, b, c, d);
    
    int order = func3(n, aa, an);
    
    //@ assert (input[0] <= 8 || input[1] <= 8) ==> (order >= 0 && order <= (n - 1));
    
    return order;
}
