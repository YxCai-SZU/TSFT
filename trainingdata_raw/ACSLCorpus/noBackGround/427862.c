#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= (b) && (b) <= 100);
    ensures \result >= 1 || \result == -1;
    ensures \result >= 1 ==> ((\result * 8) / 100) == a && ((\result * 10) / 100) == b;
*/
int64_t func(uint64_t a, uint64_t b)
{
    uint64_t diff;
    uint64_t price;
    uint64_t result;
    uint64_t temp_price;
    uint64_t a_check;
    uint64_t b_check;
    uint64_t a_result;
    uint64_t b_result;
    uint64_t temp_a_check;
    uint64_t temp_b_check;
    
    diff = b - a;
    price = diff * 50;
    
    //@ assert price == ((diff) * 50);
    
    result = 0;
    temp_price = price;
    
    /*@
        loop invariant temp_price >= 0;
        loop invariant temp_price + 10 * result == price;
        loop invariant result >= 0;
        loop invariant price == diff * 50;
        loop assigns temp_price, result;
        loop variant temp_price;
    */
    while (temp_price >= 10)
    {
        temp_price -= 10;
        result += 1;
    }
    price = result;
    
    //@ assert price == ((((diff) * 50)) / 10);
    
    a_check = price * 8;
    b_check = price * 10;
    a_result = 0;
    b_result = 0;
    
    temp_a_check = a_check;
    /*@
        loop invariant temp_a_check >= 0;
        loop invariant temp_a_check + 100 * a_result == a_check;
        loop invariant a_result >= 0;
        loop assigns temp_a_check, a_result;
        loop variant temp_a_check;
    */
    while (temp_a_check >= 100)
    {
        temp_a_check -= 100;
        a_result += 1;
    }
    a_check = a_result;
    
    //@ assert a_check == ((price * 8) / 100);
    
    temp_b_check = b_check;
    /*@
        loop invariant temp_b_check >= 0;
        loop invariant temp_b_check + 100 * b_result == b_check;
        loop invariant b_result >= 0;
        loop assigns temp_b_check, b_result;
        loop variant temp_b_check;
    */
    while (temp_b_check >= 100)
    {
        temp_b_check -= 100;
        b_result += 1;
    }
    b_check = b_result;
    
    //@ assert b_check == ((price * 10) / 100);
    
    if (a_check == a && b_check == b)
    {
        //@ assert price >= 1 ==> ((price * 8) / 100) == a && ((price * 10) / 100) == b;
        return (int64_t)price;
    }
    else
    {
        return -1;
    }
}
