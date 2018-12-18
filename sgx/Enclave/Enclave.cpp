#include "Enclave_t.h"

#include <stdarg.h>  // va_list etc.
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// printf function is defined in mojo/util.h


#include "core_math.h"
#include "mojo.h"
#include "util.h"
#include "network.h"
//--------------- the above files passed

#include "solver.h" // only supported sgd, need more time here. should be fixed already?

#include "cost.h" 
#include "activation.h"
#include "layer.h"
#include "mnist_parser.h" // file IO for mnist images


void printf(const char *fmt, ...) { 
	char buf[BUFSIZ] = { '\0' };
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(buf, BUFSIZ, fmt, ap);
	va_end(ap);
	ocall_print(buf);
}

int generate_random_number() {
//    printf("data_name: %s\n", data_name());
    ocall_print("Processing random number generation...");
    return 42;
}


mojo::network cnn;
//std::string model_file="../models/mnist_deepcnet.mojo";
std::string model_file="../models/cifar_deepcnet.mojo";

void new_network()
{
//    printf(">> ecall new_network\n");
    cnn.enable_external_threads(); 
//    printf(">> ecall enable_external_threads succeed.\n");
    if(!cnn.read((char *)model_file.c_str())) 
    {
        printf("error: could not read model.\n");
    }
    
    printf(" Mojo CNN Configuration:\n");
	printf("%s\n\n", cnn.get_configuration().c_str());
}

int cnn_outsize()
{
    return cnn.out_size();
}

int classification(float *testimage, int size)
{  
    return cnn.predict_class(testimage);
}
