#include "Enclave_t.h"

#include <stdarg.h>  // va_list etc.
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// printf function is defined in mojo/util.h

#include "cost.h" 
#include "activation.h"
#include "core_math.h"
#include "layer.h"
#include "mojo.h"
#include "util.h"
//--------------- the above files passed


//#include "mnist_parser.h" // file IO
//#include "network.h"

#include "solver.h" // only supported sgd, need more time here






void printf(const char *fmt, ...);

int generate_random_number() {
 
    ocall_print("Processing random number generation...");
    return 42;
}
