#include <stdbool.h>

/*@
    predicate is_three_digit(integer n) = 100 <= n && n <= 999;
    predicate is_palindrome(integer n) = n / 100 == n % 10;
*/

/*@
    requires is_three_digit(n);
    ensures \result ==> is_palindrome(n);
    assigns \nothing;
*/
bool is_palindrome(unsigned int n)
{
    unsigned int a;
    unsigned int c;

    //@ assert is_three_digit(n);
    //@ assert n / 100 <= 9;
    //@ assert n % 10 <= 9;

    a = n / 100;
    c = n % 10;

    //@ assert a == n / 100;
    //@ assert c == n % 10;

    return a == c;
}

/*@
    requires is_three_digit(n);
    ensures \result ==> is_palindrome(n);
    assigns \nothing;
*/
bool test_palindrome(unsigned int n)
{
    bool ret;
    ret = is_palindrome(n);
    return ret;
}
