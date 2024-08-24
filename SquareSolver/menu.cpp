#include <cmath>
#include <cstdio>

#include "rootListStruct.h"
#include "solver.h"
#include "solverTest.h"
#include "coefficientInput.h"
#include "coefficientListStruct.h"
#include "googleTests.h"

/*/ START MODE MENU /*/
int manualMode() {
    
    rootList roots = {};
    rootListInitialize(&roots);

    coefficientList coefficients = {};
    coefficientListInitialize(&coefficients);

    bool validCoefficientInput = coefficientInput(&coefficients);

    if (validCoefficientInput) {
        solve(&coefficients, &roots);
    }
    else {
        return -1;
    }

    printResult(&roots);

    rootListDestruct(&roots);
    coefficientListDestruct(&coefficients);
    return 0;
}

void testMode() {
    runAllTests();
}

void googleTestMode(int argc, char *argv[]) {
    runAllGoogleTests(argc, argv);
}
/*/ END MODE MENU /*/