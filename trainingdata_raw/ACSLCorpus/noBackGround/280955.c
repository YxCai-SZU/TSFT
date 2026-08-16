#include <stdint.h>

/*@
    requires (0 <= (X) && (X) <= 1000000000);
    ensures \result == (((X) / 500) * 1000 + (((X) % 500) / 5) * 5);
    assigns \nothing;
*/
int64_t func(int64_t X)
{
    int64_t five_hundreds_num;
    int64_t remaining_balance;
    int64_t five_num;
    int64_t result;
    
    five_hundreds_num = 0;
    remaining_balance = X;
    
    /*@
        loop invariant 0 <= five_hundreds_num;
        loop invariant five_hundreds_num <= X / 500;
        loop invariant remaining_balance == X - five_hundreds_num * 500;
        loop invariant 0 <= remaining_balance && remaining_balance <= X;
        loop assigns five_hundreds_num, remaining_balance;
        loop variant remaining_balance;
    */
    while (remaining_balance >= 500)
    {
        //@ assert remaining_balance >= 500;
        five_hundreds_num += 1;
        remaining_balance -= 500;
    }
    
    five_num = 0;
    
    /*@
        loop invariant 0 <= five_hundreds_num && five_hundreds_num <= X / 500;
        loop invariant 0 <= five_num && five_num <= (X - five_hundreds_num * 500) / 5;
        loop invariant remaining_balance == X - five_hundreds_num * 500 - five_num * 5;
        loop invariant 0 <= remaining_balance && remaining_balance <= X;
        loop assigns five_num, remaining_balance;
        loop variant remaining_balance;
    */
    while (remaining_balance >= 5)
    {
        //@ assert remaining_balance >= 5;
        five_num += 1;
        remaining_balance -= 5;
    }
    
    result = five_hundreds_num * 1000 + five_num * 5;
    //@ assert result == (((X) / 500) * 1000 + (((X) % 500) / 5) * 5);
    return result;
}

int main()
{
    return 0;
}
