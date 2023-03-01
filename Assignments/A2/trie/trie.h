typedef struct _trienode
{
    char c;
    struct _trienode *fc,*sib;
    int eow;
}_trienode;

typedef struct trie
{
    _trienode *root;
}_trie;

typedef _trie *trie;
typedef _trienode *trienode;

trie trieinit();
int triesearch(trie,char*);
void trieinsert(trie,char*);
void listall(trie);