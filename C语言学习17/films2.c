//使用结构链表
#include<stdio.h>
#include<stdlib.h>    //提供malloc()原型
#include<string.h>    //提供strcpy()原型
#define TSIZE 45      //存放片名的数组大小
struct film {
	char title[TSIZE];
	int rating;
	struct film * next;   //指向链表的下一个结构 
}; 

int main(void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];
	
	//收集并储存信息
	puts("Enter first movie title: ");
	while(gets(input)!= NULL&&input[0] !='\0')
	{
		current = (struct film *) malloc(sizeof(struct film));
		if(head == NULL) //第一个结构
		   head = current;
		else
		   prev->next = current;
		current->next = NULL;
		strcpy(current->title,input);
		puts("Enter your rating <0-10>: ");
		scanf("%d",&current->rating);
		while(getchar()!='\n')
		   continue;
		puts("Enter next movie title (empty line to stop): ");
		prev = current;
	}
	
	//给出电脑列表
	if(head == NULL)
	   printf("No data entered. "); 
	else
	   printf("Here is the movie list: \n");
	current = head;
	while(current !=NULL)
	{
		printf("Movie: %s Rating: %d\n",current->title,current->rating);
		current = current->next;
	}
	//任务已完成，因此释放所分配的内存
	current = head;
	while(current !=NULL)
	{
		free(current);
		current=current->next;
	}
	printf("Bye!\n");
	
	return 0;
}
