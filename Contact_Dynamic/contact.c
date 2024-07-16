#include "contact.h"

void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ*sizeof(struct PeoInfo));
	if(ps->data == NULL)
	{
		return ;
	}
	ps->size = 0;//设置通讯录最初只有0个元素
	ps->capacity = DEFAULT_SZ;
	
}

void CheckCapacity(struct Contact* ps)
{
	if(ps->size == ps->capacity)
	{
		struct PeoInfo* ptr =  realloc(ps->data, (ps->capacity+2)*sizeof(struct PeoInfo));
		if(ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容成功\n");
		}
	}
}

void AddContact(struct Contact* ps)
{
	//检测当前的通讯录容量
	//1.如果满了增加空间
	//2.如果没满，继续操作
	CheckCapacity(ps);
	

	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址:>");
	scanf("%s", ps->data[ps->size].addr);
	
	ps->size ++;
	printf("添加成功一条信息\n");

}

void ShowContact(const struct Contact* ps)
{
	if(ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for(i = 0; i< ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

static int FindByName(const struct Contact* ps, char name[MAX_NAME])//static 修饰的函数只能在此文件内部使用
{
	int i = 0;
	for(i = 0; i< ps->size; i++)
	{
		if(0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	
	//1.查找要删除的人在什么位置
	
//	int i = 0;
//	for(i = 0; i< ps->size; i++)
//	{
//		if(0 == strcmp(ps->data[i].name, name))
//		{
//			break;
//		}
//		
//	}//封装成函数，避免代码冗余
	
	//找到了返回名字所在元素的下标
	//找不到返回-1
	int pos = FindByName(ps, name);
	
	
	
	if(-1 == pos)
	{
		printf("要删除的人不存在\n");
	}
	//2.删除
	else
	{
		int j = 0;
		//删除数据
		for(j = pos; j < ps->size -1; j++)
		{
			ps->data[j] = ps->data[j+1];			
		}
		ps->size --;
		printf("一条信息删除成功\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if(-1 == pos)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}	
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];		
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	
	if(-1 == pos)
	{
		printf("要修改人的信息不存在\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);
				
		printf("修改完成\n");	
	}
}

static int cmp_by_name(const void* pn1, const void* pn2)
{
	
	return strcmp(((struct PeoInfo*)pn1)->name, ((struct PeoInfo*)pn2)->name);	
}

void SortContact(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_by_name);
	printf("按名字排序完成\n");
}


void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}
