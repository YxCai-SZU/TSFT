#include <stdbool.h>

/*@
requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100);
ensures \result == (a <= c && d <= b);
assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    bool answer;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;

    answer = (a <= c) && (d <= b);
    return answer;
}

int main()
{
    return 0;
}
