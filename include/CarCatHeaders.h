#ifndef CAR_CAT_HEADERS_H
#define CAR_CAT_HEADERS_H
//***********************************
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include "CatFunc.h"
#include "Cars.h"
#include "UsePuts.h"
#include "ValIndex.h"
#include "Savld.h"

// Clear screen function: Clears the console screen 
// works for both Windows and Unix-based systems

inline void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

//***********************************
#endif //CAR_CAT_HEADERS_H