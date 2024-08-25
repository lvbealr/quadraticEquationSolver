#include <cstdio>
#include <cassert>
#include <cmath>

#include "rootListStruct.h"
#include "customAssert.h"

/*/ START OF ROOTLIST STRUCT /*/
void rootListInitialize(rootList *roots) {
    customAssert(roots != NULL, POINTER_IS_NULL, __LINE__, __FILE__, __FUNCTION__);

    roots->count = 0;
    for (int index = 0; index < MAX_ROOT_COUNT; index++) {
        roots->roots[index] = INFINITY;
    }
    roots->status = INVALID;
}

void rootListDestruct(rootList *roots) {
    customAssert(roots != NULL, POINTER_IS_NULL, __LINE__, __FILE__, __FUNCTION__);

    roots->count = INVALID_COUNT;
    for (int index = 0; index < MAX_ROOT_COUNT; index++) {
        roots->roots[index] = INFINITY;
    }
    roots->status = INVALID;
}

int getRootCount(const rootList *roots) {
    customAssert(roots != NULL, POINTER_IS_NULL, __LINE__, __FILE__, __FUNCTION__);

    switch (roots->status) {
        case LINEAR_ONE_ROOT:
        case QUADRATIC_ONE_ROOT:
            return 1;
        case QUADRATIC_TWO_ROOTS:
            return 2;
        case LINEAR_NO_ROOTS:
        case QUADRATIC_NO_ROOTS:
        case LINEAR_INF_ROOTS:
        case INVALID:
        default:
            return 0;
    }
}

bool pushRoot(rootList *roots, double root) {
    customAssert(roots != NULL, POINTER_IS_NULL, __LINE__, __FILE__, __FUNCTION__);

    if ((roots->count < 0) && (roots->count >= getRootCount(roots))) {
        return false;
    }

    roots->roots[roots->count] = root;
    roots->count++;
    return true;
}

void printRoot(const rootList *roots) {
    customAssert(roots != NULL, POINTER_IS_NULL, __LINE__, __FILE__, __FUNCTION__);

    int rootCount = getRootCount(roots);
    for (int index = 0; index < rootCount; index++) {
        printf("%lg\t", roots->roots[index]);
    }
}

void setStatus(rootList *roots, solveCode status) {
    customAssert(roots != NULL, POINTER_IS_NULL, __LINE__, __FILE__, __FUNCTION__);

    roots->status = status;
}

void printResult(rootList *roots) {
    customAssert(roots != NULL, POINTER_IS_NULL, __LINE__, __FILE__, __FUNCTION__);
    
    switch (roots->status) {
        case LINEAR_INF_ROOTS: {
            printf("Infinitely many solutions");
            break;
        }
        case LINEAR_NO_ROOTS: {
            printf("No solutions");
            break;
        }
        case LINEAR_ONE_ROOT: {
            printf("It is linear (non-quadratic) "
                   "equation\nSolutions: ");
            break;
        }
        case QUADRATIC_NO_ROOTS: {
            printf("D < 0: No real solutions");
            break;
        }
        case QUADRATIC_ONE_ROOT: {
            printf("D = 0\nSolutions: ");
            break;
        }
        case QUADRATIC_TWO_ROOTS: {
            printf("D > 0\nSolutions: ");
            break;
        }
        case INVALID:
        default:
            break;
    }
    printRoot(roots);
    printf("\n");
}
/*/ END OF ROOTLIST STRUCT /*/