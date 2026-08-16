// Generated C + ACSL

typedef struct {
    int isNew;
} Photo;

typedef struct {
    int isNew;
} Video;

/*@
    requires photos_len >= 0;
    requires videos_len >= 0;
    requires photos_len > 0 ==> photos != \null;
    requires videos_len > 0 ==> videos != \null;
    requires \valid(photos + (0 .. photos_len-1));
    requires \valid(videos + (0 .. videos_len-1));
    assigns photos[0 .. photos_len-1], videos[0 .. videos_len-1];
*/
void ApplyMigration(Photo* photos, int photos_len, Video* videos, int videos_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= photos_len;
  loop invariant \forall integer k; 0 <= k < i ==> photos[k].isNew == 1;
  loop invariant \forall integer k; 0 <= k < photos_len ==> \valid(&photos[k]);
  loop invariant \forall integer k; 0 <= k < photos_len ==>
                 \at(photos[k].isNew, LoopEntry) == photos[k].isNew || k < i;
  loop assigns i, photos[0..photos_len-1].isNew;
  loop variant photos_len - i;
*/
  while ((i < photos_len))
    {
      photos[i].isNew = 1;
      i = (i + 1);
    }
  i = 0;
/*@
  loop invariant 0 <= i <= videos_len;
  loop invariant \forall integer k; 0 <= k < i ==> videos[k].isNew == 1;
  loop invariant \forall integer k; 0 <= k < videos_len ==> \valid(&videos[k]);
  loop invariant \forall integer k; 0 <= k < i ==>
    videos[k].isNew == \at(videos[k].isNew, LoopEntry) || videos[k].isNew == 1;
  loop assigns i, videos[0..videos_len-1].isNew;
  loop variant videos_len - i;
*/
  while ((i < videos_len))
    {
      videos[i].isNew = 1;
      i = (i + 1);
    }
}