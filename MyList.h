#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 数据的设计 -> 学生信息抽象出
struct student {
	char name[20];
	int age;
	char sex[5];
	char tel[20];
};

// 结构分结构去写
// 莫一种数据结构去实现什么东西的时候，单独去这一种数据结构
// 先把数据结构写对了再说
struct Node {
	struct student data;
	struct Node* next;
};

// 创建链表
struct Node* createList() {
	// 结构体变量表示表头
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}

// 创建节点
struct Node* createNode(struct student data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};

// 插入节点，头插法
void insertNodeByHead(struct Node* headNode, struct student data) {
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

// 指定位置删除
void deleteAppointNode(struct Node* headNode, char* compare_id) {
	struct Node* pNode = headNode->next;
	struct Node* pre = headNode;
	if (pNode == NULL) {
		printf("数据为空,无法删除!\n");
		return;
	}
	while (strcmp(pNode->data.name, compare_id)){
		pre = pNode;
		pNode = pNode->next;
		if (pNode == NULL) {
			printf("未找到指定位置,无法删除\n");
			return;
		}
	}
	pre->next = pNode->next;
	free(pNode);
}

// 修改功能
void modifyInfoByData(struct Node* headNode, struct Node* modifyData) {
	struct Node* pNode = headNode->next;
	if (pNode == NULL) {
		printf("数据为空，无法修改！\n");
		return;
	}
	while (strcmp(pNode->data.name, modifyData->data.name)) {
		pNode = pNode->next;
	}
	strcpy(pNode->data.name, modifyData->data.name);
	pNode->data.age = modifyData->data.age;
	strcpy(pNode->data.sex, modifyData->data.sex);
	strcpy(pNode->data.tel, modifyData->data.tel);
}

// 查找功能
struct Node* searchInfoByData(struct Node* headNode, char* compare_id) {
	struct Node* pNode = headNode->next;
	if (pNode == NULL) {
		return NULL;
	}
	while (strcmp(pNode->data.name, compare_id)) {
		pNode = pNode->next;
	}
	return pNode;
}

// 文件读操作
void readInfoFromFile(struct Node* headNode, const char* filename) {
	// 打开
	FILE* fp;
	struct student data;
	fp = fopen(filename, "rb");
	if (fp == NULL) {
		fopen(filename, "wb");
	}
	// 读取
	while (fscanf(fp, "%s%d%s%s\n", data.name, &data.age, data.sex, data.tel) != EOF) {
		insertNodeByHead(headNode, data);
	}
	//  关闭
	fclose(fp);
}

// 文件写操作
void writeInflToFile(struct Node* headNode, const char* filename) {
	FILE* fp;
	struct student data;
	fp = fopen(filename, "wb");
	struct Node* pNode = headNode->next;
	while (pNode) {
		fprintf(fp, "%s\t%d\t%s\t%s\n", pNode->data.name, pNode->data.age, pNode->data.sex, pNode->data.tel);
		pNode = pNode->next;
	}
	fclose(fp);
}

// 打印链表
void printList(struct Node* headNode) {
	struct Node* pNode = headNode->next;
	printf("姓名\t年龄\t性别\t电话\n");
	while (pNode)
	{
		// 打印字符
		printf("%s\t%d\t%s\t%s\n", pNode->data.name,pNode->data.age,pNode->data.sex,pNode->data.tel);
		pNode = pNode->next;
	}
}
