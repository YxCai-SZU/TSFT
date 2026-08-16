#include <stdbool.h>

/* ========== First code snippet (func1) ========== */

/*@ predicate is_in_range(integer a, integer b) =
      1 <= a && a <= b && b <= 20;
*/

/*@ logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = b - a;
*/

/*@ lemma sum_diff_relation:
      \forall integer a, b;
        is_in_range(a, b) ==>
        (sum(a, b) == a + b) && (diff(a, b) == b - a);
*/

long func1(long a, long b) {
    long result;
    long temp;
    bool is_even;
    long i;

    result = 0;
    temp = a + b;
    is_even = true;
    i = 0;

    while (i < temp) {
        if ((temp - i) & 1) {
            //@ assert (temp - i) % 2 == 1;
            is_even = false;
        }
        i = i + 1;
    }

    if (is_even) {
        result = temp;
        //@ assert result == sum(a, b);
    } else {
        result = b - a;
        //@ assert result == diff(a, b);
    }

    return result;
}

/* ========== Second code snippet (func2 and is_odd_func) ========== */

/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@ lemma n_squared_bound: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000; */

unsigned int func2(unsigned int n, unsigned int a)
{
    unsigned int result;

    //@ assert n * n <= 10000;
    //@ assert n * n >= a;
    
    result = n * n - a;
    return result;
}

bool is_odd_func(unsigned int n)
{
    bool ret;
    
    ret = (n % 2 != 0);
    return ret;
}

/* ========== Third code snippet (func3) ========== */

/*@
    predicate is_valid_x(integer x) = 1 <= x <= 1000;
    logic integer division_by_3(integer num, integer quot) = num - quot * 3;
*/

int func3(int x) {
    int a = 0;
    int b = 0;
    int c = 0;
    int quotient = 0;
    int remainder = x;


    while (remainder >= 3) {
        //@ assert remainder >= 3;
        quotient += 1;
        remainder -= 3;
    }
    a = quotient;

    quotient = 0;
    remainder = a;

    while (remainder >= 3) {
        //@ assert remainder >= 3;
        quotient += 1;
        remainder -= 3;
    }
    b = quotient;

    quotient = 0;
    remainder = b;

    while (remainder >= 3) {
        //@ assert remainder >= 3;
        quotient += 1;
        remainder -= 3;
    }
    c = quotient;

    if (a + b + c >= 10) {
        //@ assert a + b + c >= 10;
        return 1;
    } else {
        //@ assert a + b + c < 10;
        return 0;
    }
}

/* ========== Fourth code snippet (func4) ========== */

/*@
    predicate is_sum(integer a, integer b, integer c) =
        a + b == c || b + c == a || c + a == b;
 */

int func4(int a, int b, int c)
{
    int bc;
    int ac;
    int ab;
    int result;

    bc = 0;
    ac = 0;
    ab = 0;

    if (a + b == c)
    {
        bc = 1;
    }
    //@ assert bc == 1 ==> a + b == c;

    if (b + c == a)
    {
        ac = 1;
    }
    //@ assert ac == 1 ==> b + c == a;

    if (c + a == b)
    {
        ab = 1;
    }
    //@ assert ab == 1 ==> c + a == b;

    if (bc || ac || ab)
    {
        result = 1;
    }
    else
    {
        //@ assert !(bc || ac || ab);
        result = 0;
    }
    //@ assert result == 1 <==> (bc == 1 || ac == 1 || ab == 1);
    return result;
}

/* ========== Synthesized function: process_packet ========== */

int process_packet(long a, long b, unsigned int n, unsigned int a_val, int x, int p, int q, int r) {
    long step1_result;
    unsigned int step2_result;
    int step3_result;
    int step4_result;
    int final_result;

    step1_result = func1(a, b);

    step2_result = func2(n, a_val);
    //@ assert step2_result == n * n - a_val;

    step3_result = func3(x);
    //@ assert step3_result == 0 || step3_result == 1;

    step4_result = func4(p, q, r);
    //@ assert step4_result == 1 <==> (p + q == r || q + r == p || r + p == q);

    if (is_odd_func(step1_result) && step3_result == 1 && step4_result == 1) {
        final_result = 1;
    } else {
        final_result = 0;
    }

    //@ assert final_result == 1 <==> (is_odd(step1_result) && step3_result == 1 && step4_result == 1);

    return final_result;
}
