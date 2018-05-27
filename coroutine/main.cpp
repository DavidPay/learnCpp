#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include "coroutine.h"

struct twoint
{
	int a;
	int b;
};

void PointTest()
{
	int ** plv2 = NULL;
	int * plv1;
	int * arr[10];
	int tmp;

	plv1 = (int *)malloc(sizeof(int) * 10);

	//	plv2 = (int **)malloc(sizeof(int *) * 10);
	//	for (int i = 1; i<10; i++)
	//		plv2[i] = (int*)malloc(sizeof(int));

//	plv2[0] = plv1;

	int ** k;
	int * a[10];
	int *mid;
	twoint * t;
	int a1 = sizeof(twoint);
	int a2 = sizeof(t);
	mid = (int *)malloc(sizeof(int) * 10);
	mid[0] = 5;
	mid[1] = 2;
	//	k = &mid;
	a[0] = mid;
	k = (int **)malloc(sizeof(int*) * 10);
	memset(k, 0, sizeof(int*) * 10);
	k[0] = mid;
	//*k = (int *)malloc(sizeof(int*) * 10); Î´³õÊ¼»¯ Òì³£
}


void test3(schedule *s, void *ud)
{
	int *data = (int*)ud;
	for (int i = 0; i < 3; i++)
	{
		printf("test3 i=%d\n", i);
		coroutine_yield(s);
		printf("yield co id = %d.\n", *data);
	}
}

void coroutine_test()
{
	printf("coroutine_test3 begin\n");
	schedule *s = coroutine_open();

	int a = 11;
	int id1 = coroutine_new(s, test3, &a);
	int id2 = coroutine_new(s, test3, &a);
	
	while (coroutine_status(s, id1) && coroutine_status(s, id2))
	{
		printf("\nresume co id = %d.\n", id1);
		coroutine_resume(s, id1);
	//	printf("resume co id = %d.\n", id2);  
	//	coroutine_resume(s, id2);  
	}

	int id3 = coroutine_new(s, test3, &a);
	while (coroutine_status(s, id3))
	{
		printf("\nresume co id = %d.\n", id3);
		coroutine_resume(s, id3);
	}

	printf("coroutine_test3 end\n");
	coroutine_close(s);
}

int main()
{
	PointTest();
	coroutine_test();
	while (1) {};
	return 0;
}
