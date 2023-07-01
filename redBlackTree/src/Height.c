#include <stdlib.h>

#include "Tree.h"
#include "Height.h"
#include "CheckColor.h"

int BlackHeight(TTree* tree) {
    if (!tree) {
        return 1;
    }
    return BlackHeight(tree->Left) + BlackNode(tree);
}
