#ifndef BACKTRACE_H
#define BACKTRACE_H

#include <execinfo.h>
#include <stdlib.h> /* for free() */
#include <iostream>

using namespace std;

static void backtrace()
{
	void *callers[100];
	size_t size = backtrace(callers, 100);
	char **symbols = backtrace_symbols(callers, size);
	for (size_t i = 0; i < size; i++) cerr << symbols[i] << endl;
	free(symbols);
}

#endif
