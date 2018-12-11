#include "Enclave_t.h"

#include <stdarg.h>  // va_list etc.
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include "cost.h" 
#include "activation.h"
#include "core_math.h"
//--------------- the above files passed


//#include "mnist_parser.h" // file IO
#include "solver.h" // only supported sgd, need more time here

#include "layer.h"


//------------------------------------------------------------------------------
/*
* printf:
*   Invokes OCALL to display the enclave buffer to the terminal.
*/
//------------------------------------------------------------------------------
void printf(const char *fmt, ...) { 
	char buf[BUFSIZ] = { '\0' };
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(buf, BUFSIZ, fmt, ap);
	va_end(ap);
	ocall_print(buf);
}

void printf(const char *fmt, ...);

int generate_random_number() {
 
    ocall_print("Processing random number generation...");
    return 42;
}
