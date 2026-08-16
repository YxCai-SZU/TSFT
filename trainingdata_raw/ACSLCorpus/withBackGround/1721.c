#include <stdbool.h>

/*@ predicate is_celebrated(integer x) = 
      x == 3 || x == 5 || x == 7; */

/*@ requires 3 <= x && x <= 7;
    ensures \result <==> is_celebrated(x);
    assigns \nothing;
 */
bool will_growth_be_celebrated(int x)
{
    //@ assert 3 <= x && x <= 7;
    return (x == 3) || (x == 5) || (x == 7);
}

int main(void)
{
    return 0;
}
