#include <stdbool.h>

/*@
    requires ((a) >= 1 && (a) <= 100 &&
        (b) >= 1 && (b) <= 100 &&
        (c) >= 1 && (c) <= 100);
    ensures \result == true <==> 
            ((a + b + c) % 2 == 0) && (((a) + (b)) >= (c) && ((a) + (c)) >= (b) && ((b) + (c)) >= (a));
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int sum;
    bool is_even = false;
    int temp_sum;
    int ab;
    int ac;
    int bc;

    //@ assert a + b <= 200;
    //@ assert a + c <= 200;
    //@ assert b + c <= 200;

    sum = a + b + c;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 2 == sum % 2;
        loop invariant ((a) >= 1 && (a) <= 100 &&
        (b) >= 1 && (b) <= 100 &&
        (c) >= 1 && (c) <= 100);
        loop assigns temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
    }

    if (temp_sum == 0)
    {
        is_even = true;
    }

    ab = a + b;
    ac = a + c;
    bc = b + c;

    //@ assert (ab >= c && ac >= b && bc >= a) <==> (((a) + (b)) >= (c) && ((a) + (c)) >= (b) && ((b) + (c)) >= (a));

    if ((ab >= c && ac >= b && bc >= a) && is_even)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    return 0;
}
