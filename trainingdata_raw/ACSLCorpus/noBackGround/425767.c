#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= (n));
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int count_colors_parallelogram(int n, int k)
{
    int num_colors = 1;
    int i = 1;

    /*@
        loop invariant ((1 <= ((n)) && ((n)) <= 100 && 1 <= ((k)) && ((k)) <= ((n))) &&
        1 <= (i) && (i) <= (n) &&
        (num_colors) >= 1 &&
        (num_colors) <= (i) &&
        ((i) > 1 ==> (num_colors) <= (n)));
        loop assigns i, num_colors;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert ((1 <= ((n)) && ((n)) <= 100 && 1 <= ((k)) && ((k)) <= ((n))) &&         1 <= (i) && (i) <= (n) &&         (num_colors) >= 1 &&         (num_colors) <= (i) &&         ((i) > 1 ==> (num_colors) <= (n)));
        
        if (i >= k)
        {
            num_colors = num_colors + 1;
        }
        
        i = i + 1;
        
        //@ assert ((1 <= ((n)) && ((n)) <= 100 && 1 <= ((k)) && ((k)) <= ((n))) &&         1 <= (i) && (i) <= (n) &&         (num_colors) >= 1 &&         (num_colors) <= (i) &&         ((i) > 1 ==> (num_colors) <= (n)));
    }
    
    //@ assert num_colors >= 1 && num_colors <= n;
    return num_colors;
}
