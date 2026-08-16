#include <stdbool.h>

/*@ requires 1 <= x <= 100000;
    ensures \result == (x >= 2000 || x % 200 == 0);
    assigns \nothing; */
bool func(int x)
{
    bool is_affordable;
    int temp_x;
    
    if (x >= 2000) {
        is_affordable = true;
    } else {
        temp_x = x;
        /*@ loop invariant 1 <= x <= 100000;
            loop invariant 0 <= temp_x <= x;
            loop invariant temp_x % 200 == x % 200;
            loop assigns temp_x;
            loop variant temp_x; */
        while (temp_x >= 200) {
            temp_x -= 200;
        }
        //@ assert temp_x == 0 ==> x % 200 == 0;
        is_affordable = (temp_x == 0);
    }
    
    return is_affordable;
}

int main(void)
{
    return 0;
}
