#include <stdbool.h>

/*@
    requires length >= 0;
    ensures \result == true <==> length % 2 == 0;
    assigns \nothing;
*/
bool is_even(int length)
{
    int count = length;

    /*@
        loop invariant ((count) >= 0 && (count) <= (length) && (count) % 2 == (length) % 2);
        loop assigns count;
    */
    while (count > 1)
    {
        //@ assert count > 1 && count % 2 == length % 2;
        count -= 2;
    }

    //@ assert count == 0 || count == 1;
    return count == 0;
}

int main()
{
    return 0;
}
