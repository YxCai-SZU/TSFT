#include <stdbool.h>

/*@
    requires -1000 <= x <= 1000;
    ensures \result == (x >= -500 && x <= 500);
    assigns \nothing;
*/
bool check_range(int x)
{
    bool result;
    //@ assert -1000 <= x <= 1000;
    result = (x >= -500 && x <= 500);
    //@ assert result == (x >= -500 && x <= 500);
    return result;
}

/*@
    ensures \result == (x > 0);
    assigns \nothing;
*/
bool check_positive(int x)
{
    bool result;
    result = (x > 0);
    //@ assert result == (x > 0);
    return result;
}

int main()
{
    int positive_list[5];
    bool result;
    
    positive_list[0] = 1;
    positive_list[1] = 7;
    positive_list[2] = 12;
    positive_list[3] = 4;
    positive_list[4] = 25;
    
    //@ assert -1000 <= positive_list[0] <= 1000;
    result = check_range(positive_list[0]);
    //@ assert result == (positive_list[0] >= -500 && positive_list[0] <= 500);
    //@ assert result;
    
    return 0;
}
