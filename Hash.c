#include <stdbool.h>
#include <math.h>


typedef struct element {
    int key;
    int value;
} element;


typedef struct table {
    element *HT[100];
} table;


void insert(int key, int value)
{
    for(i = 0; i <= strlen(key); i++)
      HT-> HT[key] = HT[key];
}


void search(int key)
{
  int h = (*H -> hash)(k, H- > size);
  if (H -> HT[h] == NULL) return NULL;
  key = probe (H, H -> HT[h], key);
  return key;
}


void multiply(int k)
{
    int A = 0.6180339887
    return (int) (m(kA % 1));
}


void divide(int k)
{
    return k % m;
}


void inithashtable()
{
  
}


void hashfunc(int key)
{
    int hashstring(const char* s) {
      int key = 0;
      while (*s) {
        key = key*37 + *s++;
      }
      return key;
    }
}


void probe(int key, int value)
{
    int probe = hashfunc(value);
    int i;
    for(i = 0; i < hashtable; i++)
    { 
        if(HT[probe] == value)
            return TRUE;  
        probe = fmod((probe+1), m);
    }
    return FALSE; 
}


void print_datastructure(int HT)
{
    int i=0;
    while( (hashtable -> HT[i]) != NULL)
    {
       printf(" %s \t", hashtable -> HT[i] -> );
       hashtable -> HT[i] = hashtable -> HT[i] -> next;
     printf("\n");
     i++;
    }

}


int main()
{
    inithashtable()
    
    parse_exec();
    print_datastructure();
    return 0;
}