#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == n * n;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    result = n * n;
    return result;
}

enum Pet {
    Dog,
    Cat,
    Bird
};

struct PetInfo {
    enum Pet tag;
    int age;
};

/*@
    assigns \nothing;
*/
void choose_pets(void)
{
    int dog_age;
    int cat_age;
    int bird_age;
    dog_age = 5;
    cat_age = 3;
    bird_age = 2;
    //@ assert ((dog_age) >= 5);
    //@ assert ((cat_age) > 0);
    //@ assert ((bird_age) > 0);
}
