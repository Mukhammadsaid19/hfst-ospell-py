%module swig_example

// Add necessary symbols to generated header
%{
#include "swig-example.h"

%}

// Process symbols in header
%include "std_string.i" 
%include "swig-example.h"

