#include "Array.h"

#include <string.h>
#include <stdbool.h>


Array* arrayCreate()
{
	struct Array* array = NULL;
	array = malloc(sizeof(*array));
	if (NULL == array)
	{
		return NULL;
	}
	// 存放数据的指针
	array->p = NULL;
	// p指针的空间大小
	array->size = 0;
	// 数据类型的大小
	array->typeSize = 0;
	// p指针已经使用的空间大小
	array->len = 0;
	// 值复制函数
	array->dup = NULL;
	// 值释放函数
	array->free = NULL;
	// 值比较函数
	array->match = NULL;

	return array;


}

void arrayInit(Array* array, int size, int typeSize)
{
	if (NULL == array
		|| typeSize <= 0
		|| size < 0)
	{
		return;
	}


}