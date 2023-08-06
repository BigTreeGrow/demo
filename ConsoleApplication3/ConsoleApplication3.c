/*数组方面的练习


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct array              //为一个数组创建信息结构
{
    int size;             //数组尺寸
    int used;
    int* arr;
};

/*@函数：void dump(struct array* array)
 *入口函数：array
 *函数功能：遍历元素，并打印元素索引和元素
 */
void dump(struct array* array)
{
    int idx;
    for (idx = 0; idx < array->used; idx++)
        printf("[%02d]:%08d\n", idx, array->arr[idx]);
}

/*@函数：void alloc(struct array* array)
 *入口函数：array
 *函数功能：申请内存空间大小
 */
void alloc(struct array* array)
{
    array->arr = (int*)malloc(array->size * sizeof(int));
}

/*@函数：int insert(struct array* array,int elem)
 *入口函数：array   elem
 *函数功能：插入元素，并按照大小排序
 *          小的在前大的在口*/

int insert(struct array* array, int elem)
{
    int idx;
    if (array->used > array->size)
        return -1;
    for (idx = 0; idx < array->used; idx++) {
        if (array->arr[idx] > elem)
            break;
    }
    if (idx < array->used)
        memmove(&array->arr[idx + 1], &array->arr[idx],
            (array->used - idx) * sizeof(int));
    array->arr[idx] = elem;
    array->used++;
    return idx;

}


/*@函数：int delete(struct array* array, int idx)
 *入口函数：array   idx
 *函数功能：删除对应位置元素，并将后面的元素迁移连接
 *          */

int delete(struct array* array, int idx)
{
    if (idx < 0 || idx >= array->used)
        return -1;
    memmove(&array->arr[idx], &array->arr[idx + 1],
        (array->used - idx - 1) * sizeof(int));
    array->used--;
    return 0;
}

/*@函数：int search(struct array *array, int elem)
 *入口函数：array   elem
 *函数功能：寻找对应位置元素，并返回索引
 *          */
int search(struct array* array, int elem)
{
    int idx;
    for (idx = 0; idx < array->used; idx++)
    {
        if (array->arr[idx] == elem)
            return idx;
        if (array->arr[idx] > elem)
            return -1;
    }
    return -1;
}


int main()
{
    int idx;
    struct array ten_int = { 10 , 0,NULL };
    alloc(&ten_int);                     /*申请10个int元素大小的内存空间，并由ten_int->arr获得
                                           申请内存地址*/
    if (!ten_int.arr)                    //如果申请失败
        return -1;
    insert(&ten_int, 1);
    insert(&ten_int, 3);
    insert(&ten_int, 4);
    insert(&ten_int, 2);
    insert(&ten_int, 7);
    insert(&ten_int, 8);
    insert(&ten_int, 2);
    printf("=== insert 1, 3, 4,2,7,8,2\n");
    dump(&ten_int);
    idx = search(&ten_int, 2);
    printf("2 is at position %d\n", idx);
    idx = search(&ten_int, 9);
    printf("9 is at position %d\n", idx);
    delete(&ten_int, 6);
    dump(&ten_int);
    printf("=== delete [0] element \n");
    delete(&ten_int, 0);
    dump(&ten_int);
    return 0;

}