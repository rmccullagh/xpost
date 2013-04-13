#include <stdio.h>
#include "ob.h"

char *types[] = { TYPES(AS_STR) "invalid"};

SINGLETONS(DEFINE_SINGLETON)

object consint(integer i){
	object o;
	o.tag = integertype;
	o.int_.val = i;
	return o;
}

object consreal(real r){
	object o;
	o.tag = realtype;
	o.real_.val = r;
}

void dumpcompobject(object o){
	printf(" %u %u %u %u>",
			(unsigned int)o.comp_.tag,
			(unsigned int)o.comp_.sz,
			(unsigned int)o.comp_.ent,
			(unsigned int)o.comp_.off);
}

void dumpobject(object o){
	switch(o.tag) {
		default:
		case invalidtype: printf("<invalid object>"); break;

		case marktype: printf("<mark>"); break;
		case integertype: printf("<integer %d>", (int)o.int_.val); break;
		case realtype: printf("<real %f>", (float)o.real_.val);

		case stringtype: printf("<string"); dumpcompobject(o); break;
		case arraytype: printf("<array"); dumpcompobject(o); break;
		case dicttype: printf("<dict"); dumpcompobject(o); break;
	}
}

