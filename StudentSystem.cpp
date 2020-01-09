/*
	1������
	2�����ݽṹ�����
	3������
*/
#include <stdio.h>
#include <stdlib.h>
#include <MyList.h>
struct Node* list = createList();
struct Node* pNode;

// �˵����
void menu() {
	// ���в���ͬ�����ļ�
	printf("---------------------------------------------------\n");
	printf("\t\t0.¼����Ϣ\n");
	printf("\t\t1.�����Ϣ\n");
	printf("\t\t2.ɾ����Ϣ\n");
	printf("\t\t3.�޸���Ϣ\n");
	printf("\t\t4.������Ϣ\n");
	printf("\t\t5.�˳�ϵͳ\n");
	printf("---------------------------------------------------\n");
}

// �û��Ľ���
// ������ѡ�˵��������Ӧ������
void keyDown() {
	int choice = 0;
	struct student data;
	scanf("%d", &choice);
	switch (choice)
	{
	case 0:
		printf("------------------¼����Ϣ------------------\n");
		printf("������ѧ������,����,�Ա�,�绰\n");
		fflush(stdin);  // ��ջ�����
		scanf("%s%d%s%s", data.name, &data.age, data.sex, data.tel); // ��ַ
		insertNodeByHead(list, data);
		break;
	case 1:
		printf("------------------�����Ϣ------------------\n");
		printList(list);
		break;
	case 2:
		printf("------------------ɾ����Ϣ------------------\n");
		printf("������ɾ����ѧ������:");
		scanf("%s", data.name);
		deleteAppointNode(list, data.name);
		break;
	case 3:
		printf("------------------�޸���Ϣ------------------\n");
		printf("������Ҫ�޸ĵ�ѧ������:");
		scanf("%s", data.name);
		pNode = searchInfoByData(list, data.name);
		printf("�������޸ĺ������\t����\t�Ա�\t�绰\n");
		scanf("%s%d%s%s", pNode->data.name, &pNode->data.age, pNode->data.sex, pNode->data.tel);
		modifyInfoByData(list, pNode);
		break;
	case 4:
		printf("------------------������Ϣ------------------\n");
		printf("��������ҵ�ѧ������:");
		scanf("%s", data.name);
		pNode = searchInfoByData(list, data.name);
		if (pNode == NULL) {
			printf("δ�ҵ������Ϣ���޷�ɾ����\\n");
			system("pause");
		}
		else {
			printf("����\t����\t�Ա�\t�绰\n");
			printf("%s\t%d\t%s\t%s\n", pNode->data.name, pNode->data.age, pNode->data.sex, pNode->data.tel);
		}
		break;
	case 5:
		printf("�����˳�\n");
		writeInflToFile(list, "1.txt");
		system("pause");
		exit(0);
		break;
	default:
		printf("ѡ�����,��������\n");
		system("pause");
		break;
	}
}

// ������
int main() {
	readInfoFromFile(list, "1.txt");
	while (1) {
		menu();
		keyDown();
		system("pause");
		system("cls");
	}
	// �����������
	
	system("pause");
	return 0;
}