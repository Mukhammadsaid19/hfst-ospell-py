#include "ospell.h"

void swig_example_hello();
void link_liba_hello(std::string path);

hfst_ospell::Speller *createSpeller(std::string lex_path, std::string error_path);
hfst_ospell::Transducer *createTransducer(std::string lex_path);
void lookup(hfst_ospell::Transducer *tr, std::string word);