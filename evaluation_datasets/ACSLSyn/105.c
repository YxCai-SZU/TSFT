#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int* a, size_t len) =
        len == 4 &&
        \valid(a + (0 .. 3)) &&
        a[0] >= 1 && a[0] <= 10000 &&
        a[1] >= 1 && a[1] <= 10000 &&
        a[2] >= 1 && a[2] <= 10000 &&
        a[3] >= 1 && a[3] <= 10000;

    logic integer array_sum{L}(int* a) =
        a[0] + a[1] + a[2] + a[3];

    lemma array_length:
        \forall int* a, size_t len; valid_array(a, len) ==> len == 4;
*/

size_t func(int* a, size_t len) {
    size_t ans;
    int temp1;
    int temp2;
    int temp3;

    //@ assert len == 4;

    ans = 0;

    temp1 = (a[0] < a[1]) ? a[0] : a[1];
    ans = ans + (size_t)temp1;

    temp2 = (a[2] < a[3]) ? a[2] : a[3];
    ans = ans + (size_t)temp2;

    temp3 = ((a[0] + a[2]) < (a[1] + a[3])) ? (a[0] + a[2]) : (a[1] + a[3]);
    ans = ans + (size_t)temp3;

    //@ assert ans >= 0;
    //@ assert ans <= (size_t)(a[0] + a[1] + a[2] + a[3]);

    return ans;
}

struct Computer {
    uint32_t ram;
    uint32_t disk_size;
};

/*@
    predicate valid_computer(integer ram, integer disk_size) =
        ram >= 0 && disk_size >= 0;

    logic integer total_memory(integer ram, integer disk_size) =
        ram + disk_size;
*/

struct Computer upgrade_disk(uint32_t ram, uint32_t disk_size, uint32_t new_disk_size) {
    struct Computer ret;
    //@ assert valid_computer(ram, disk_size);
    ret.ram = ram;
    ret.disk_size = new_disk_size;
    //@ assert ret.ram == ram;
    return ret;
}

struct Computer upgrade_based_on_resources(int* a, size_t len, uint32_t ram, uint32_t disk_size, uint32_t new_disk_size) {
    size_t min_score;
    struct Computer upgraded;

    /* Compute minimal resource score */
    min_score = func(a, len);

    /* Perform disk upgrade */
    upgraded = upgrade_disk(ram, disk_size, new_disk_size);

    return upgraded;
}

/* Example usage */
int main(void) {
    int resources[4] = {2, 3, 5, 7};
    size_t len = 4;
    uint32_t ram = 8;
    uint32_t disk_size = 256;
    uint32_t new_disk_size = 512;
    struct Computer result;

    result = upgrade_based_on_resources(resources, len, ram, disk_size, new_disk_size);

    //@ assert result.ram == 8;
    //@ assert result.disk_size == 512;

    return 0;
}
