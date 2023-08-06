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
	// ������ݵ�ָ��
	array->p = NULL;
	// pָ��Ŀռ��С
	array->size = 0;
	// �������͵Ĵ�С
	array->typeSize = 0;
	// pָ���Ѿ�ʹ�õĿռ��С
	array->len = 0;
	// ֵ���ƺ���
	array->dup = NULL;
	// ֵ�ͷź���
	array->free = NULL;
	// ֵ�ȽϺ���
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