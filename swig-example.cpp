#include <iostream>
#include "swig-example.h"

void swig_example_hello()
{
    std::cout << "Hello from swig-example" << std::endl;
}

void link_liba_hello(std::string path)
{
	std::cout << path << std::endl;
	FILE *transducer_source = fopen(path.c_str(), "r");
	std::cout << transducer_source << std::endl;

	hfst_ospell::Transducer *tr = new hfst_ospell::Transducer(transducer_source);

	std::cout << tr->lookup("bola").top().first << std::endl;
}

hfst_ospell::Transducer* createTransducer(std::string lex_path) {
	FILE *lex_source = fopen(lex_path.c_str(), "r");
	hfst_ospell::Transducer *lex = new hfst_ospell::Transducer(lex_source);
	return lex;
}

void lookup(hfst_ospell::Transducer* tr, std::string word) {
	std::cout << tr->lookup(&word[0]).top().first << std::endl;
}

hfst_ospell::Speller* createSpeller(std::string lex_path, std::string error_path) {
	FILE *lex_source = fopen(lex_path.c_str(), "r");
	FILE *error_source = fopen(error_path.c_str(), "r");

	hfst_ospell::Transducer *lex = new hfst_ospell::Transducer(lex_source);
	hfst_ospell::Transducer *err = new hfst_ospell::Transducer(error_source);

	hfst_ospell::Speller *speller = new hfst_ospell::Speller(err, lex);

	return speller;
}


