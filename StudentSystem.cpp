/*
	1、界面
	2、数据结构的设计
	3、交互
*/
#include <stdio.h>
#include <stdlib.h>
#include <MyList.h>
struct Node* list = createList();
struct Node* pNode;

// 菜单设计
void menu() {
	// 所有操作同步到文件
	printf("---------------------------------------------------\n");
	printf("\t\t0.录入信息\n");
	printf("\t\t1.浏览信息\n");
	printf("\t\t2.删除信息\n");
	printf("\t\t3.修改信息\n");
	printf("\t\t4.查找信息\n");
	printf("\t\t5.退出系统\n");
	printf("---------------------------------------------------\n");
}

// 用户的交互
// 根据所选菜单项，做出相应的事情
void keyDown() {
	int choice = 0;
	struct student data;
	scanf("%d", &choice);
	switch (choice)
	{
	case 0:
		printf("------------------录入信息------------------\n");
		printf("请输入学生姓名,年龄,性别,电话\n");
		fflush(stdin);  // 清空缓冲区
		scanf("%s%d%s%s", data.name, &data.age, data.sex, data.tel); // 地址
		insertNodeByHead(list, data);
		break;
	case 1:
		printf("------------------浏览信息------------------\n");
		printList(list);
		break;
	case 2:
		printf("------------------删除信息------------------\n");
		printf("请输入删除的学生姓名:");
		scanf("%s", data.name);
		deleteAppointNode(list, data.name);
		break;
	case 3:
		printf("------------------修改信息------------------\n");
		printf("输入需要修改的学生姓名:");
		scanf("%s", data.name);
		pNode = searchInfoByData(list, data.name);
		printf("请输入修改后的姓名\t年龄\t性别\t电话\n");
		scanf("%s%d%s%s", pNode->data.name, &pNode->data.age, pNode->data.sex, pNode->data.tel);
		modifyInfoByData(list, pNode);
		break;
	case 4:
		printf("------------------查找信息------------------\n");
		printf("请输入查找的学生姓名:");
		scanf("%s", data.name);
		pNode = searchInfoByData(list, data.name);
		if (pNode == NULL) {
			printf("未找到相关信息，无法删除！\\n");
			system("pause");
		}
		else {
			printf("姓名\t年龄\t性别\t电话\n");
			printf("%s\t%d\t%s\t%s\n", pNode->data.name, pNode->data.age, pNode->data.sex, pNode->data.tel);
		}
		break;
	case 5:
		printf("正常退出\n");
		writeInflToFile(list, "1.txt");
		system("pause");
		exit(0);
		break;
	default:
		printf("选择错误,重新输入\n");
		system("pause");
		break;
	}
}

// 主函数
int main() {
	readInfoFromFile(list, "1.txt");
	while (1) {
		menu();
		keyDown();
		system("pause");
		system("cls");
	}
	// 测试链表代码
	
	system("pause");
	return 0;
}