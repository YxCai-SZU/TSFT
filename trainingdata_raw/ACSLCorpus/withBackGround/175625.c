#include <stdbool.h>

enum Pet {
    Dog,
    Cat,
    Bird
};

struct Dog_data {
    char* breed;
    unsigned short age;
};

struct Cat_data {
    char* color;
    unsigned short age;
};

struct Bird_data {
    char* species;
    unsigned char wingspan;
};

union Pet_data {
    struct Dog_data dog;
    struct Cat_data cat;
    struct Bird_data bird;
};

struct Pet_full {
    enum Pet tag;
    union Pet_data data;
};

/*@ predicate is_old_dog(struct Pet_full p) = 
      p.tag == Dog && p.data.dog.age > 10; */

/*@ logic integer Dog_age(struct Pet_full p) = 
      p.tag == Dog ? p.data.dog.age : 0; */

/*@ lemma check_dog: 
      \forall struct Pet_full p; p.tag == Dog ==> !(p.tag == Cat); */

/*@ lemma is_no_kitten: 
      \forall struct Pet_full p; (p.tag == Dog || p.tag == Bird) ==> !(p.tag == Cat); */

/*@ lemma is_not_puppy: 
      \forall struct Pet_full p; (p.tag == Cat || p.tag == Bird) ==> !(p.tag == Dog); */

/*@ lemma is_not_baby_bird: 
      \forall struct Pet_full p; (p.tag == Dog || p.tag == Cat) ==> !(p.tag == Bird); */

/*@ lemma is_mammal: 
      \forall struct Pet_full p; (p.tag == Dog || p.tag == Cat) ==> \true; */

/*@ lemma is_not_mammal: 
      \forall struct Pet_full p; p.tag == Bird ==> \true; */

int main() {
    return 0;
}
