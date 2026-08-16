#include <limits.h>

/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 1000000; */

/*@ logic integer div2(integer n) = n / 2; */
/*@ logic integer div5(integer n) = n / 5; */
/*@ logic integer div15(integer n) = n / 15; */

/*@ lemma div2_nonneg: \forall integer n; 1 <= n ==> div2(n) >= 0; */
/*@ lemma div5_nonneg: \forall integer n; 1 <= n ==> div5(n) >= 0; */
/*@ lemma div15_nonneg: \forall integer n; 1 <= n ==> div15(n) >= 0; */

/*@ lemma div2_bound: \forall integer n; 1 <= n <= 1000000 ==> div2(n) <= 500000; */
/*@ lemma div5_bound: \forall integer n; 1 <= n <= 1000000 ==> div5(n) <= 200000; */
/*@ lemma div15_bound: \forall integer n; 1 <= n <= 1000000 ==> div15(n) <= 66666; */

/*@ lemma subtraction_bound: \forall integer n; 1 <= n <= 1000000 ==> 
        div2(n) - div5(n) <= div2(n); */

/*@ lemma addition_bound: \forall integer n; 1 <= n <= 1000000 ==> 
        div2(n) - div5(n) + div15(n) <= div2(n) + 1; */

/*@ requires is_valid_n(n);
    ensures \result >= 0;
    ensures \result <= n / 2 + 1;
    assigns \nothing;
 */
int func(int n)
{
    int res;
    int temp_n;
    int count;
    int count2;
    int temp_n2;
    int temp_n3;
    int count3;
    
    res = 0;
    temp_n = n;
    count = 0;
    count2 = 0;
    
    /*@ loop invariant 1 <= n <= 1000000;
        loop invariant 0 <= count <= n / 2;
        loop invariant temp_n == n - 2 * count;
        loop invariant temp_n >= 0;
        loop assigns temp_n, count;
        loop variant temp_n;
     */
    while (temp_n >= 2)
    {
        temp_n -= 2;
        count += 1;
    }
    res = count;
    
    temp_n2 = n;
    /*@ loop invariant 1 <= n <= 1000000;
        loop invariant 0 <= count2 <= n / 5;
        loop invariant temp_n2 == n - 5 * count2;
        loop invariant temp_n2 >= 0;
        loop assigns temp_n2, count2;
        loop variant temp_n2;
     */
    while (temp_n2 >= 5)
    {
        temp_n2 -= 5;
        count2 += 1;
    }
    
    //@ assert res >= count2;
    //@ assert res - count2 <= n / 2;
    res = res - count2;
    
    temp_n3 = n;
    count3 = 0;
    /*@ loop invariant 1 <= n <= 1000000;
        loop invariant 0 <= count3 <= n / 15;
        loop invariant temp_n3 == n - 15 * count3;
        loop invariant temp_n3 >= 0;
        loop assigns temp_n3, count3;
        loop variant temp_n3;
     */
    while (temp_n3 >= 15)
    {
        temp_n3 -= 15;
        count3 += 1;
    }
    
    //@ assert count3 >= 0;
    //@ assert res + count3 <= n / 2 + 1;
    res = res + count3;
    
    return res;
}

int main()
{
    return 0;
}
