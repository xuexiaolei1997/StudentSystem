#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ���ݵ���� -> ѧ����Ϣ�����
struct student {
	char name[20];
	int age;
	char sex[5];
	char tel[20];
};

// �ṹ�ֽṹȥд
// Īһ�����ݽṹȥʵ��ʲô������ʱ�򣬵���ȥ��һ�����ݽṹ
// �Ȱ����ݽṹд������˵
struct Node {
	struct student data;
	struct Node* next;
};

// ��������
struct Node* createList() {
	// �ṹ�������ʾ��ͷ
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}

// �����ڵ�
struct Node* createNode(struct student data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};

// ����ڵ㣬ͷ�巨
void insertNodeByHead(struct Node* headNode, struct student data) {
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

// ָ��λ��ɾ��
void deleteAppointNode(struct Node* headNode, char* compare_id) {
	struct Node* pNode = headNode->next;
	struct Node* pre = headNode;
	if (pNode == NULL) {
		printf("����Ϊ��,�޷�ɾ��!\n");
		return;
	}
	while (strcmp(pNode->data.name, compare_id)){
		pre = pNode;
		pNode = pNode->next;
		if (pNode == NULL) {
			printf("δ�ҵ�ָ��λ��,�޷�ɾ��\n");
			return;
		}
	}
	pre->next = pNode->next;
	free(pNode);
}

// �޸Ĺ���
void modifyInfoByData(struct Node* headNode, struct Node* modifyData) {
	struct Node* pNode = headNode->next;
	if (pNode == NULL) {
		printf("����Ϊ�գ��޷��޸ģ�\n");
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

// ���ҹ���
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

// �ļ�������
void readInfoFromFile(struct Node* headNode, const char* filename) {
	// ��
	FILE* fp;
	struct student data;
	fp = fopen(filename, "rb");
	if (fp == NULL) {
		fopen(filename, "wb");
	}
	// ��ȡ
	while (fscanf(fp, "%s%d%s%s\n", data.name, &data.age, data.sex, data.tel) != EOF) {
		insertNodeByHead(headNode, data);
	}
	//  �ر�
	fclose(fp);
}

// �ļ�д����
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

// ��ӡ����
void printList(struct Node* headNode) {
	struct Node* pNode = headNode->next;
	printf("����\t����\t�Ա�\t�绰\n");
	while (pNode)
	{
		// ��ӡ�ַ�
		printf("%s\t%d\t%s\t%s\n", pNode->data.name,pNode->data.age,pNode->data.sex,pNode->data.tel);
		pNode = pNode->next;
	}
}
