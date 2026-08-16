#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c, integer d,
                     integer e, integer f, integer g, integer h) =
        0 <= a <= 10 && 0 <= b <= 10 && 0 <= c <= 10 && 0 <= d <= 10 &&
        0 <= e <= 10 && 0 <= f <= 10 && 0 <= g <= 10 && 0 <= h <= 10;

    lemma sum1_bound: \forall integer a,b,c;
        0 <= a <= 10 && 0 <= b <= 10 && 0 <= c <= 10 ==> 0 <= a+b+c <= 30;
    lemma sum2_bound: \forall integer d,e,f;
        0 <= d <= 10 && 0 <= e <= 10 && 0 <= f <= 10 ==> 0 <= d+e+f <= 30;
    lemma sum3_bound: \forall integer g,h;
        0 <= g <= 10 && 0 <= h <= 10 ==> 0 <= g+h <= 20;
    lemma product_bound: \forall integer s1,s2;
        0 <= s1 <= 30 && 0 <= s2 <= 30 ==> 0 <= s1*s2 <= 900;
*/

/*@
    requires bounds(a,b,c,d,e,f,g,h);
    ensures \result == true <==> (a+b+c)*(d+e+f) <= g+h;
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e, int f, int g, int h)
{
    int sum1;
    int sum2;
    int sum3;
    int product;
    bool result;

    //@ assert 0 <= a+b <= 20;
    //@ assert 0 <= c+d <= 20;
    //@ assert 0 <= e+f <= 20;
    //@ assert 0 <= a+b+c <= 30;
    //@ assert 0 <= d+e+f <= 30;
    //@ assert 0 <= g+h <= 20;

    sum1 = a + b + c;
    sum2 = d + e + f;
    sum3 = g + h;

    //@ assert 0 <= sum1 <= 30;
    //@ assert 0 <= sum2 <= 30;
    //@ assert 0 <= sum3 <= 20;

    product = sum1 * sum2;

    //@ assert 0 <= product <= 900;

    result = (product <= sum3);
    return result;
}

int main()
{
    return 0;
}
