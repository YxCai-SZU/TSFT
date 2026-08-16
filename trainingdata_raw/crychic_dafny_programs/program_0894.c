// Generated C + ACSL

#include <stddef.h>

typedef struct {
    char* context;
    int* tags;
    int tags_len;
    void* category;
} Blog;

typedef struct {
    Blog* blogs;
    int blogs_len;
} BlogSystem;

/*@
    assigns \nothing;
*/
void InitTestData(void)
{
  int t1; /* unsupported init: Microsoft.Dafny.AllocateClass */
  int t2; /* unsupported init: Microsoft.Dafny.AllocateClass */
  int tags = 0;
  /*@ assert tags >= 0 && tags <= 2147483647; */
  int c1; /* unsupported init: Microsoft.Dafny.AllocateClass */
  int c2; /* unsupported init: Microsoft.Dafny.AllocateClass */
  int categories = 0;
  /*@ assert categories >= 0 && categories <= 2147483647; */
  Blog b1;
  b1.context = "this is my first blog, hello world";
  Blog b2;
  b2.context = "this is my second blog, hello python";
  b2.tags = 0;
  Blog b3;
  b3.context = "this is my third blog, hello python";
  b3.tags = 0;
  b3.category = (void*)&c2;
  Blog b4;
  b4.context = "this is my fourth blog, hello python";
  b4.tags = 0;
  b4.category = (void*)&c1;
  int blogs = 0;
  /*@ assert blogs >= 0 && blogs <= 2147483647; */
}

/*@
    requires \valid(this);
    requires \valid_read(this->blogs + (0 .. this->blogs_len-1));
    requires this->blogs_len >= 0;
    assigns \nothing;
*/
int* FindBlogsByTag(BlogSystem* this, int searchTag)
{
  int result = 0;
  /*@ assert result >= 0 && result <= 2147483647; */
  int i = 0;
  /*@ assert i == 0; */
  /*@ assert result == 0; */
/*@
  loop invariant 0 <= i <= this->blogs_len;
  loop invariant result >= 0;
  loop invariant result <= i;
  loop invariant \valid_read(this->blogs + (0 .. this->blogs_len-1));
  loop assigns i, result;
  loop variant this->blogs_len - i;
*/
  while ((i < this->blogs_len))
    {
      /*@ assert 0 <= i < this->blogs_len; */
      /*@ assert \valid_read(&this->blogs[i]); */
      Blog blog = this->blogs[i];
      int old_result = result;
      /*@ assert result >= 0; */
      if (searchTag != -1)
      {
        result = (result + 0);
        /*@ assert result == old_result; */
      }
      /*@ assert result >= 0; */
      /*@ assert result <= i + 1; */
      i = (i + 1);
      /*@ assert i <= this->blogs_len; */
    }
  /*@ assert i == this->blogs_len; */
  /*@ assert result >= 0; */
  return &result;
}