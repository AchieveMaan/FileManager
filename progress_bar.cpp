#include "progress_bar.h"

double progress = 0.0;

bool setProgress(double pgrs) {
    progress = pgrs;
    printProgress();
    return true;
}

void printProgress() {
    //for (int i = 0; i < progress && i < 100; i++) {
        std::cout << progress << "%";
    //}
    std::cout << std::endl;
}