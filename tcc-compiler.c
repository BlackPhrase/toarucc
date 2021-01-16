/* vim: tabstop=4 shiftwidth=4
 * This file is part of the Toaru Compiler Collection (toarucc)
 * and is licensed under the ISC license. See LICENSE for details.
 *
 * tcc-compiler - C compiler
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TOARUCC_VERSION_MAJOR 0
#define TOARUCC_VERSION_MINOR 1
#define TOARUCC_VERSION_PATCH 0


int skip_compiling = 0;
int skip_assembling = 0;
int skip_linking = 0;

void preprocess()
{
	// TODO
};

void tokenize()
{
    fprintf(stderr, "Tokenizing...\n");
};

void parse()
{
    fprintf(stderr, "Parsing...\n");
};

void optimize()
{
    fprintf(stderr, "Optimizing...\n");
};

void compile()
{
    fprintf(stderr, "Compiling...\n");

    tokenize();
    parse();

    optimize();
};

void link()
{
    fprintf(stderr, "Linking...\n");
};

void print_version()
{
    //fprintf(stderr, "toarucc version %d.%d.%d\n", TOARUCC_VERSION_MAJOR, TOARUCC_VERSION_MINOR, TOARUCC_VERSION_PATCH);
    fprintf(stderr, "toarucc %d.%d.%d\n", TOARUCC_VERSION_MAJOR, TOARUCC_VERSION_MINOR, TOARUCC_VERSION_PATCH);
    fprintf(stderr, "Copyright (C) 2020 ToaruCC Contributors\n");
    fprintf(stderr, "This is free software; see the source for copying conditions.	There is NO warranty; not even MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n");
};

int main(int argc, char **argv)
{
    fprintf(stderr, "hello world\n");

    for(int i = 0; i < argc; ++i)
    {
        if(!strcmp(argv[i], "--version"))
            print_version();

		// Only preprocess the code, without compiling it
		if(!strcmp(argv[i], "-E"))
			skip_compiling = 1;
		
		// Only compile the code, without assembling it
		if(!strcmp(argv[i], "-S"))
			skip_assembling = 1;
		
        // Only compile the code, without linking it
        if(!strcmp(argv[i], "-c"))
            skip_linking = 1;
		
    };

	preprocess();
	
	if(!skip_compiling)
	{
		compile();

		if(!skip_assembling)
		{
			assemble();
		
			if(!skip_linking)
				link();
		};
	};

    fprintf(stderr, "Done!\n");
    return EXIT_SUCCESS;
};