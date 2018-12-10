#include "Enclave_t.h"

#include <stdarg.h>  // va_list etc.
#include <stdio.h>

using namespace std;

//#include "cost.h" // test: add cnn related files 1-by-1 
#include "activation.h"

//#include "solver.h"

//#include "layer.h"

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

int generate_random_number() {
    ocall_print("Processing random number generation...");
    return 42;
}
