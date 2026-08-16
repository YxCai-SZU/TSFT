#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_zero(integer v) = v == 0; */
/*@ predicate is_one(integer v) = v == 1; */

/*@ logic integer func2_logic(integer x, integer y) =
      (x == 0 && y == 0) ? 0 :
      (x == 0 && y == 1) ? 1 :
      (x == 1 && y == 0) ? 1 :
      0; */

/*@ lemma func2_correct: 
      \forall integer x, y; 
      0 <= x <= 1 && 0 <= y <= 1 ==> 
      func2_logic(x, y) == ((x == 0) ? y : (1 - y)); */

int func_not(int x)
{
    int result;
    //@ assert 0 <= x <= 1;
    if (x == 0)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    //@ assert (x == 0 ==> result == 1) && (x == 1 ==> result == 0);
    return result;
}

int func2(int x, int y)
{
    int result;
    //@ assert 0 <= x <= 1 && 0 <= y <= 1;
    if (x == 0)
    {
        result = y;
    }
    else
    {
        result = 1 - y;
    }
    //@ assert result == func2_logic(x, y);
    return result;
}

/*@ logic integer func3_logic(integer x, integer y, integer z) =
      (x == 0 && y == 0 && z == 0) ? 0 :
      (x == 0 && y == 0 && z == 1) ? 1 :
      (x == 0 && y == 1 && z == 0) ? 1 :
      (x == 0 && y == 1 && z == 1) ? 0 :
      (x == 1 && y == 0 && z == 0) ? 1 :
      (x == 1 && y == 0 && z == 1) ? 0 :
      (x == 1 && y == 1 && z == 0) ? 0 :
      1; */

int func3(int x, int y, int z)
{
    int result;
    int tmp;
    //@ assert 0 <= x <= 1 && 0 <= y <= 1 && 0 <= z <= 1;
    tmp = func2(y, z);
    //@ assert tmp == func2_logic(y, z);
    if (x == 0)
    {
        result = tmp;
    }
    else
    {
        result = 1 - tmp;
    }
    //@ assert (x == 0 ==> result == func2_logic(y, z)) && (x == 1 ==> result == 1 - func2_logic(y, z));
    return result;
}

/*@
    predicate in_range(integer n) = 1 <= n <= 10000;

    logic integer compute_result(integer n) = (1000 - n % 1000) % 1000;

    lemma result_lemma: \forall integer n; in_range(n) ==> compute_result(n) >= 0 && compute_result(n) < 1000;
*/

uint32_t func_mod1000(uint32_t n)
{
    uint32_t result;
    uint32_t i;

    result = (1000 - n % 1000) % 1000;
    i = 0;

    while (i < 10)
    {
        //@ assert i < 10;
        i = i + 1;
    }

    //@ assert result == compute_result(n);
    return result;
}

uint32_t validate_packet_checksum(uint32_t packet_id, int control_bit1, int control_bit2, int control_bit3)
{
    int parity_result;
    uint32_t modulo_result;
    int final_checksum;

    //@ assert 1 <= packet_id <= 10000;
    //@ assert 0 <= control_bit1 <= 1 && 0 <= control_bit2 <= 1 && 0 <= control_bit3 <= 1;

    parity_result = func3(control_bit1, control_bit2, control_bit3);

    modulo_result = func_mod1000(packet_id);
    //@ assert modulo_result == compute_result(packet_id);

    if (modulo_result % 2 == 0)
    {
        final_checksum = parity_result;
    }
    else
    {
        final_checksum = func_not(parity_result);
    }

    //@ assert final_checksum == (func3_logic(control_bit1, control_bit2, control_bit3) ^ ((compute_result(packet_id) % 2) == 0 ? 0 : 1));
    //@ assert final_checksum == 0 || final_checksum == 1;
    return (uint32_t)final_checksum;
}
