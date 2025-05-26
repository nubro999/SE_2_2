#include "boundary.h"
#include <iostream>


int main() {
    FileBoundary boundary("input.txt", "output.txt");
    doTask(boundary);
    return 0;
}