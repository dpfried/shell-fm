/*
	vim:syntax=c tabstop=2 shiftwidth=2 noexpandtab

	Shell.FM - split.c
	Copyright (C) 2006 by Jonas Kramer
	Published under the terms of the GNU General Public License (GPL).
*/

#include <string.h>
#include <stdlib.h>
#include <assert.h>

char ** split(char * string, const char * del, unsigned * pnsplt) {
	char ** splt = NULL;
	unsigned nsplt = 0;
	register char * ptr = string;

	if(!string)
		return NULL;
	
	while(* ptr) {
		while(strchr(del, * ptr))
			++ptr;
		if(* ptr) {
			register unsigned length = 0;
			splt = realloc(splt, sizeof(char *) * (nsplt + 1));
			assert(splt != NULL);
			splt[nsplt] = calloc(strlen(ptr) + 1, sizeof(char));
			assert(splt[nsplt] != NULL);
			while(!strchr(del, * ptr))
				splt[nsplt][length++] = * (ptr++);
			splt[nsplt] = realloc(splt[nsplt], length + 1);
			++nsplt;
		}
	}

	pnsplt && (* pnsplt = nsplt);
	return splt;
}
