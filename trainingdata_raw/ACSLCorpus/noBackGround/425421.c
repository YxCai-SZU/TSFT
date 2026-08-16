#include <stdbool.h>

/*@
    requires 1 <= x < y <= 12;
    ensures \result == ((((x) == 1 && ((y) == 3 || (y) == 5 || (y) == 7 || (y) == 8 || (y) == 10 || (y) == 12)) ||
        ((x) == 3 && ((y) == 1 || (y) == 5 || (y) == 7 || (y) == 8 || (y) == 10 || (y) == 12)) ||
        ((x) == 5 && ((y) == 1 || (y) == 3 || (y) == 7 || (y) == 8 || (y) == 10 || (y) == 12)) ||
        ((x) == 7 && ((y) == 1 || (y) == 3 || (y) == 5 || (y) == 8 || (y) == 10 || (y) == 12)) ||
        ((x) == 8 && ((y) == 1 || (y) == 3 || (y) == 5 || (y) == 7 || (y) == 10 || (y) == 12)) ||
        ((x) == 10 && ((y) == 1 || (y) == 3 || (y) == 5 || (y) == 7 || (y) == 8 || (y) == 12)) ||
        ((x) == 12 && ((y) == 1 || (y) == 3 || (y) == 5 || (y) == 7 || (y) == 8 || (y) == 10)) ||
        ((x) == 4 && ((y) == 6 || (y) == 9 || (y) == 11)) ||
        ((x) == 6 && ((y) == 4 || (y) == 9 || (y) == 11)) ||
        ((x) == 9 && ((y) == 4 || (y) == 6 || (y) == 11)) ||
        ((x) == 11 && ((y) == 4 || (y) == 6 || (y) == 9)) ||
        ((x) == 2 && (y) == 2) ? 1 : 0) == 1);
*/
bool func(unsigned int x, unsigned int y)
{
    unsigned int group_1[7] = {1, 3, 5, 7, 8, 10, 12};
    unsigned int group_2[4] = {4, 6, 9, 11};
    unsigned int group_3[1] = {2};
    
    bool found_x_in_group_1 = false;
    bool found_y_in_group_1 = false;
    bool found_x_in_group_2 = false;
    bool found_y_in_group_2 = false;
    bool found_x_in_group_3 = false;
    bool found_y_in_group_3 = false;
    
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= 7;
        loop invariant found_x_in_group_1 ==> (\exists integer k; 0 <= k < 7 && group_1[k] == x);
        loop invariant found_y_in_group_1 ==> (\exists integer k; 0 <= k < 7 && group_1[k] == y);
        loop invariant !found_x_in_group_1 ==> (\forall integer k; 0 <= k < i ==> group_1[k] != x);
        loop invariant !found_y_in_group_1 ==> (\forall integer k; 0 <= k < i ==> group_1[k] != y);
        loop assigns i, found_x_in_group_1, found_y_in_group_1;
        loop variant 7 - i;
    */
    while (i < 7)
    {
        if (group_1[i] == x)
        {
            found_x_in_group_1 = true;
        }
        if (group_1[i] == y)
        {
            found_y_in_group_1 = true;
        }
        i++;
    }
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant found_x_in_group_2 ==> (\exists integer k; 0 <= k < 4 && group_2[k] == x);
        loop invariant found_y_in_group_2 ==> (\exists integer k; 0 <= k < 4 && group_2[k] == y);
        loop invariant !found_x_in_group_2 ==> (\forall integer k; 0 <= k < i ==> group_2[k] != x);
        loop invariant !found_y_in_group_2 ==> (\forall integer k; 0 <= k < i ==> group_2[k] != y);
        loop assigns i, found_x_in_group_2, found_y_in_group_2;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (group_2[i] == x)
        {
            found_x_in_group_2 = true;
        }
        if (group_2[i] == y)
        {
            found_y_in_group_2 = true;
        }
        i++;
    }
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 1;
        loop invariant found_x_in_group_3 ==> (\exists integer k; 0 <= k < 1 && group_3[k] == x);
        loop invariant found_y_in_group_3 ==> (\exists integer k; 0 <= k < 1 && group_3[k] == y);
        loop invariant !found_x_in_group_3 ==> (\forall integer k; 0 <= k < i ==> group_3[k] != x);
        loop invariant !found_y_in_group_3 ==> (\forall integer k; 0 <= k < i ==> group_3[k] != y);
        loop assigns i, found_x_in_group_3, found_y_in_group_3;
        loop variant 1 - i;
    */
    while (i < 1)
    {
        if (group_3[i] == x)
        {
            found_x_in_group_3 = true;
        }
        if (group_3[i] == y)
        {
            found_y_in_group_3 = true;
        }
        i++;
    }
    
    bool group_1_result = found_x_in_group_1 && found_y_in_group_1;
    bool group_2_result = found_x_in_group_2 && found_y_in_group_2;
    bool group_3_result = found_x_in_group_3 && found_y_in_group_3;
    
    bool result = group_1_result || group_2_result || group_3_result;
    
    //@ assert result == ((((x) == 1 && ((y) == 3 || (y) == 5 || (y) == 7 || (y) == 8 || (y) == 10 || (y) == 12)) ||         ((x) == 3 && ((y) == 1 || (y) == 5 || (y) == 7 || (y) == 8 || (y) == 10 || (y) == 12)) ||         ((x) == 5 && ((y) == 1 || (y) == 3 || (y) == 7 || (y) == 8 || (y) == 10 || (y) == 12)) ||         ((x) == 7 && ((y) == 1 || (y) == 3 || (y) == 5 || (y) == 8 || (y) == 10 || (y) == 12)) ||         ((x) == 8 && ((y) == 1 || (y) == 3 || (y) == 5 || (y) == 7 || (y) == 10 || (y) == 12)) ||         ((x) == 10 && ((y) == 1 || (y) == 3 || (y) == 5 || (y) == 7 || (y) == 8 || (y) == 12)) ||         ((x) == 12 && ((y) == 1 || (y) == 3 || (y) == 5 || (y) == 7 || (y) == 8 || (y) == 10)) ||         ((x) == 4 && ((y) == 6 || (y) == 9 || (y) == 11)) ||         ((x) == 6 && ((y) == 4 || (y) == 9 || (y) == 11)) ||         ((x) == 9 && ((y) == 4 || (y) == 6 || (y) == 11)) ||         ((x) == 11 && ((y) == 4 || (y) == 6 || (y) == 9)) ||         ((x) == 2 && (y) == 2) ? 1 : 0) == 1);
    
    return result;
}
