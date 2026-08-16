// Generated C + ACSL

typedef struct {
    int suggest;
} Post;

/*@
    requires posts != \null;
    requires posts_len >= 0;
    requires \valid(posts + (0 .. posts_len-1));
    assigns posts[0 .. posts_len-1].suggest;
*/
void AddSuggestField(Post* posts, int posts_len)
{
  int i = 0;
  int defaultUrl; /* unsupported init: Microsoft.Dafny.AllocateClass */
/*@
  loop invariant 0 <= i <= posts_len;
  loop invariant \forall integer k; 0 <= k < i ==>
                 posts[k].suggest == defaultUrl;
  loop invariant \forall integer k; 0 <= k < posts_len ==>
                 \valid(posts+k);
  loop assigns i, posts[0..posts_len-1].suggest;
  loop variant posts_len - i;
*/
  while ((i < posts_len))
    {
      posts[i].suggest = defaultUrl;
      i = (i + 1);
    }
}

/*@
  predicate Valid(int *value, integer len) =
    len > 0;
*/