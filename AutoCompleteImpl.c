#include "AutoCompleteImpl.h"


void printPaths(struct TrieNode* node);

struct TrieNode *createTrieNode() {
    //TODO implement logic for creating an Trie node
    struct TrieNode *node=(struct TrieNode *)malloc(sizeof(TrieNode));
    //if(node){
        int i;
        node->isEndOfWord=false;
        //node->label='\0';

        for(i=0;i<ALPHABET_SIZE;i++){

            node->children[i]=NULL;
        }

   // }
    return node;
}

void insert(struct TrieNode *root, const char *word) {
    //TODO implement logic for inserting a word to the tree


    int level;
    int length=strlen(word);
    int index;

    struct TrieNode *pCrawl=root;

    for(level=0;level<length;level++){

        index=CHAR_TO_INDEX(word[level]);
        if(!pCrawl->children[index]){
            pCrawl->children[index]=createTrieNode();
            pCrawl->children[index]->label=word[level];
            pCrawl->children[index]->isEndOfWord=false;

        }
        pCrawl=pCrawl->children[index];
    }
    pCrawl->isEndOfWord=true;
}

struct TrieNode *search(struct TrieNode *root, const char *word) {
    //TODO implement search logic for Tries tree.
    //TODO This function should return last node of the node sequence where we found given word

    int level;
    int length = strlen(word);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(word[level]);

        if (!pCrawl->children[index])
            break;

        pCrawl = pCrawl->children[index];
    }

    return pCrawl;

}

void print_path (char *path, int len,char prefix[]){
  int i,j;
  for(j=0;j<strlen(prefix);j++){
        printf("%c", prefix[j]);
    }
  for(i = 1; i < len; i++){

     printf("%c", path[i]);

  }

    printf("\n");
}

void print(struct TrieNode* node, char *path, int len,char prefix[]) {
  // sanity check
  if (! node)
    return;

  // current node is part of the current path, so add it
  path[len++] = node->label;

  // if it is an end node then print the path
  if (node->isEndOfWord)
    print_path(path, len,prefix);

  // now go through the children and recursive call
  int i = 0;
  for (i = 0; i < 26; i++) {
    if (node->children[i] != NULL) {
      print(node->children[i], path, len,prefix);
    }
  }
}

void traverse(char prefix[], struct TrieNode *root) {
    //TODO implement tree traversal logic here. Use this to traverse underneath tree
    //TODO TIP: use this function to print words once you find the node in search function

    char path[1000];
    struct TrieNode *rnode=search(root,prefix);
    //printPaths(rnode);
    //char path[1000];
    //print(rnode,path,0);
    print(rnode,path,0,prefix);


}
