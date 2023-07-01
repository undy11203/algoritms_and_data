#ifndef ALLOC
#define ALLOC

TAVLTree* Createloc(size_t size);

TAVLTree* Alloc(int N, TAVLTree* tree);

void Freeloc(TAVLTree* tree, int N);

#endif
