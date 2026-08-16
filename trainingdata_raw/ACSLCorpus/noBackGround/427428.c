#include <stdbool.h>

/*@
    requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires 0 <= k && k < 24 * 60;
    requires ((h1) <= (h2) && ((h1) == (h2) ==> (m1) <= (m2)));
    ensures \result == (((h2) - (h1)) * 60 + ((m2) - (m1)) - (k));
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int start_minutes;
    int end_minutes;
    int ans;

    //@ assert (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    start_minutes = h1 * 60 + m1;
    //@ assert (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    end_minutes = h2 * 60 + m2;
    ans = end_minutes - start_minutes - k;
    return ans;
}

int main()
{
    int h1;
    int m1;
    int h2;
    int m2;
    int k;
    int result;

    h1 = 10;
    m1 = 0;
    h2 = 15;
    m2 = 0;
    k = 30;
    //@ assert (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    //@ assert (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    //@ assert ((h1) <= (h2) && ((h1) == (h2) ==> (m1) <= (m2)));
    result = func(h1, m1, h2, m2, k);
    //@ assert result == 270;
    return 0;
}
