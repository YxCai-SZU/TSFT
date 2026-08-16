#include <limits.h>

/*@
    predicate valid_range(integer N) = 1 <= N <= 100;
*/

/*@
    logic integer discount_value(integer count) = 200 * count;
*/

/*@
    logic integer total_value(integer N) = 800 * N;
*/

/*@
    lemma discount_bound:
        \forall integer N, count;
        valid_range(N) && 0 <= count <= N / 15 ==> discount_value(count) <= 200 * (N / 15);
*/

/*@
    lemma total_bound:
        \forall integer N, i;
        valid_range(N) && 0 <= i <= N ==> 800 * i <= total_value(N);
*/

/*@
    requires valid_range(N);
    ensures \result == total_value(N) - discount_value(N / 15);
*/
int func(int N)
{
    int result = 0;
    int n = N;
    int count = 0;
    
    // Manual division by 15
    /*@
        loop invariant 0 <= n <= N;
        loop invariant n == N - 15 * count;
        loop invariant 0 <= count <= N / 15;
        loop assigns n, count;
        loop variant n;
    */
    while (n >= 15)
    {
        n -= 15;
        count += 1;
    }
    
    // Manual multiplication by 200
    int discount = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= count;
        loop invariant discount == 200 * i;
        loop assigns discount, i;
        loop variant count - i;
    */
    while (i < count)
    {
        discount += 200;
        i += 1;
    }
    
    // Manual multiplication by 800
    i = 0;
    /*@
        loop invariant 0 <= i <= N;
        loop invariant result == 800 * i;
        loop assigns result, i;
        loop variant N - i;
    */
    while (i < N)
    {
        result += 800;
        i += 1;
    }
    
    result -= discount;
    
    //@ assert result == total_value(N) - discount_value(count);
    return result;
}
