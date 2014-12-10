#include <stdbool.h>
#include <stdlib.h>


struct list {
  ht_elem data;
  struct list* next;
};
typedef struct list* list;


void list_free(list p, void (*elem_free)(elem)) {
  list q;
  while (p != NULL) {
    if (p->data != NULL && elem_free != NULL)
      (*elem_free)(p->data);
    q = p->next;
    free(p);
    p = q;
  }
}
//Got a lot of help and infromation from http://www.cs.yale.edu/homes/aspnes/pinewiki/C%282f%29HashTables.html
//and https://gist.github.com/tonious/1377667. I was extremely confused even with help from the book.

table table_new(int init_size,
		 ht_key (*elem_key)(elem),
		 bool (*equal)(key1, key2),
		 int (*hash)(key, int m))
{ REQUIRES(init_size > 1);
  chain* A = xcalloc(init_size, sizeof(chain));
  table H = xmalloc(sizeof(struct table));
  H.size = init_size;
  H.num = 0;
  H.array = A;
  H.elem_key = elem_key;
  H.equal = equal;
  H.hash = hash;
  ENSURES(is_table(H));
  return H;
}

insert(table H, elem) 
{ REQUIRES(is_table(H));
  ht_elem old_e;
  key = (*H->elem_key)(e);
  int h = (*H->hash)(k, H->size);
  if (H.array[h] == NULL)
    H.array[h] = chain_new();
  old_e = chain_insert(H, H->array[h], e);
  if (old_e != NULL) return old_e;
  H.num++;
  ENSURES(is_table(H));
  ENSURES(table_search(H, (*H->elem_key)(e)) == e); /* pointer equality */
  return NULL;
}

search(table H, key)
{ REQUIRES(is_table(H));
  int h = (*H->hash)(k, H->size);
  if (H->array[h] == NULL) return NULL;
  elem = chain_search(H, H->array[h], k);
  ENSURES(e == NULL || (*H->equal)((*H->elem_key)(e), k));
  return e;
}