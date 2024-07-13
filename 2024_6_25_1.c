#include <stdio.h>
#include <string.h>
#include <assert.h>

//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src);//两种断言都可以
//	
//	char* ret = dest;
//	while(*dest != '\0')
//	{
//		dest++;		
//	}
//	while(*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	
//	return 0;
//}


int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while(*str1 == *str2)
	{
		if(*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
		
	}
	
	if(*str1 > *str2)
		return 1;
	else
		return -1;
	//Linux写法 ：return (*str1 - *str2);
}

int main()
{
	char* p1 = "abcdef";
	char* p2 = "sqwer";
	int ret = my_strcmp(p1, p2);
	printf("%d\n", ret);

	return 0;
}
