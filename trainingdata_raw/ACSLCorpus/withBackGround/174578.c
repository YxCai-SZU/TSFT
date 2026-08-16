#include <limits.h>

/*@
    predicate is_in_range(integer n) = -1290 <= n && n <= 1290;
    
    logic integer cube(integer n) = n * n * n;
    logic integer square(integer n) = n * n;
    
    lemma cube_in_range: \forall integer n; is_in_range(n) ==> 
        -1290*1290*1290 <= cube(n) && cube(n) <= 1290*1290*1290;
    lemma square_in_range: \forall integer n; is_in_range(n) ==> 
        -1290*1290 <= square(n) && square(n) <= 1290*1290;
*/

/*@
    requires is_in_range(n);
    ensures \result == cube(n);
    assigns \nothing;
*/
int func1(int n)
{
    //@ assert is_in_range(n);
    //@ assert -1290*1290 <= n*n && n*n <= 1290*1290;
    //@ assert -1290*1290*1290 <= n*n*n && n*n*n <= 1290*1290*1290;
    return n * n * n;
}

/*@
    requires is_in_range(x);
    ensures \result == square(x);
    assigns \nothing;
*/
int func2(int x)
{
    //@ assert is_in_range(x);
    //@ assert -1290*1290 <= x*x && x*x <= 1290*1290;
    return x * x;
}

int main()
{
    return 0;
}
