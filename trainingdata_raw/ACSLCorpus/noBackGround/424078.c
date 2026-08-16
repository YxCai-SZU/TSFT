#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == ((((n)) / 100) * 100 + (((((n)) % 100)) / 5) * 5);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result = 0;
    size_t temp_n = n;
    size_t hundred = 0;
    size_t five = 0;

    // Calculate n / 100
    /*@
        loop invariant 1 <= n && n <= 10000;
        loop invariant 0 <= hundred && hundred <= n / 100;
        loop invariant temp_n == n - hundred * 100;
        loop invariant temp_n >= 0;
        loop assigns hundred, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 100)
    {
        //@ assert hundred + 1 <= n / 100;
        hundred += 1;
        temp_n -= 100;
        //@ assert temp_n == n - hundred * 100;
    }
    result += hundred * 100;

    // Calculate n % 100 / 5
    /*@
        loop invariant 1 <= n && n <= 10000;
        loop invariant 0 <= hundred && hundred <= n / 100;
        loop invariant 0 <= five && five <= (n - hundred * 100) / 5;
        loop invariant temp_n == n - hundred * 100 - five * 5;
        loop invariant temp_n >= 0;
        loop assigns five, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 5)
    {
        //@ assert five + 1 <= (n - hundred * 100) / 5;
        five += 1;
        temp_n -= 5;
        //@ assert temp_n == n - hundred * 100 - five * 5;
    }
    result += five * 5;

    //@ assert result == n / 100 * 100 + (n % 100) / 5 * 5;
    return result;
}

int main()
{
    return 0;
}
