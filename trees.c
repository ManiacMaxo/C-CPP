#include <stdio.h>
#include <stdlib.h>

struct tree_t {
    float height;
    int age;
};

struct forest_t {
    int tree_count;
    struct tree_t trees[1000];
};

struct forest_t ageTrees(struct forest_t *forest) {
    for (int i = 0; i < forest->tree_count; i++) {
        forest->trees[i].age++;
        forest->trees[i].height += 0.1 + ((float)rand() / (float)(RAND_MAX)) * 1.9;
    }
    return *forest;
}

void printTree(struct tree_t tree, int num) {
    printf("tree %d height: %f\tage: %d\n", num, tree.height, tree.age);
}

void printForest(struct forest_t forest) {
    for (int i = 0; i < forest.tree_count; i++) {
        prinTree(forest.trees, i);
    }
}

struct forest_t cutOldTrees(struct forest_t *forest, int age_threshold) {
    for (int i = 0; i < forest->tree_count; i++) {
        if (forest->trees[i].age >= age_threshold) {
            printf("Cut tree %d with age %f\n", i, forest->trees[i].age);
            forest->trees[i].age = 1;
            forest->trees[i].height = 0.5;
        }
    }
    return *forest;
}
struct forest_t cutTallTrees(struct forest_t *forest, float height_threshold) {
    for (int i = 0; i < forest->tree_count; i++) {
        if (forest->trees[i].height >= height_threshold) {
            printf("Cut tree %d with height %f\n", i, forest->trees[i].height);
            forest->trees[i].age = 1;
            forest->trees[i].height = 0.5;
        }
    }
    return *forest;
}

struct forest_t makeForest(struct forest_t *forest) {
    for (int i = 0; i < forest->tree_count; i++) {
        forest->trees[i].age = 0;
        forest->trees[i].height = 0;
    }
    return *forest;
}

int main(int argc, char **argv) {
    struct forest_t forest;
    makeForest(&forest);
    int years = atoi(argv[1]), age_threshold = atoi(argv[2]), j = 0;
    float height_threshold = atoi(argv[3]);
    for (int i = 0; i < years; i++) {
        printForest(forest);
        ageTrees(&forest);
        cutOldTrees(&forest, age_threshold);
        cutTallTrees(&forest, height_threshold);
        printForest(forest);
    }
}
