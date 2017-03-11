#include <stdio.h>
#include "option.h"

OPTION_TYPEDEF(int, option_int);

struct cat
	{
	int legs;
	};

OPTION_TYPEDEF(struct cat, option_cat);
OPTION_TYPEDEF(struct cat *, option_pointer_cat);

int main()
	{
	option_int a[5];
	OPTION_NONE(&a[0]);
	OPTION_NONE(&a[1]);
	OPTION_SOME(&a[2], 5);
	OPTION_SOME(&a[3], -52);
	OPTION_SOME(&a[4], 12);

	for (int i = 0; i < 5; i++)
		{
		switch (a[i].type)
			{
			case OPTION_NONE:
				printf("a[%d] is storing nothing\n", i);
				break;
			case OPTION_SOME:
				printf("a[%d] is storing %d\n", i, a[i].value);
				break;
			}
		}

	struct cat c = {5};
	option_cat oc;
	OPTION_SOME(&oc, c);
	switch (oc.type)
		{
		case OPTION_NONE:
			printf("I have no cat\n");
			break;
		case OPTION_SOME:
			printf("I have a cat with %d legs\n", oc.value.legs);
			break;
		}

	option_pointer_cat opc;
	OPTION_SOME(&opc, &c);
	switch (opc.type)
		{
		case OPTION_NONE:
			printf("I have no pointy cat\n");
			break;
		case OPTION_SOME:
			printf("I have a pointy cat with %d legs\n", opc.value->legs);
			break;
		}
	OPTION_NONE(&opc);
	switch (opc.type)
		{
		case OPTION_NONE:
			printf("I have no pointy cat\n");
			break;
		case OPTION_SOME:
			printf("I have a pointy cat with %d legs\n", opc.value->legs);
			break;
		}
	}
