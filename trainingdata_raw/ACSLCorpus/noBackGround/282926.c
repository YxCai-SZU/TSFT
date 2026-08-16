#include <stdint.h>

/*@
    requires ((length) > 0 && (width) > 0 && (height) > 0 &&
        (uint64_t)(length) * (uint64_t)(width) * (uint64_t)(height) <= UINT32_MAX);
    ensures \result == ((length) * (width) * (height));
    assigns \nothing;
*/
uint32_t calculate_volume(uint32_t length, uint32_t width, uint32_t height)
{
    // Variable declarations at top of scope
    uint64_t intermediate_product;
    uint32_t final_volume;

    //@ assert ((length) > 0 && (width) > 0 && (height) > 0 &&         (uint64_t)(length) * (uint64_t)(width) * (uint64_t)(height) <= UINT32_MAX);
    
    intermediate_product = (uint64_t)length * (uint64_t)width;
    //@ assert intermediate_product == (uint64_t)length * (uint64_t)width;
    
    intermediate_product = intermediate_product * (uint64_t)height;
    //@ assert intermediate_product == (uint64_t)length * (uint64_t)width * (uint64_t)height;
    
    //@ assert intermediate_product <= UINT32_MAX;
    
    final_volume = (uint32_t)intermediate_product;
    //@ assert final_volume == ((length) * (width) * (height));
    
    return final_volume;
}

int main()
{
    uint32_t length = 10;
    uint32_t width = 20;
    uint32_t height = 30;
    uint32_t volume;
    
    //@ assert ((length) > 0 && (width) > 0 && (height) > 0 &&         (uint64_t)(length) * (uint64_t)(width) * (uint64_t)(height) <= UINT32_MAX);
    
    volume = calculate_volume(length, width, height);
    
    return 0;
}
