#include<iostream>
using namespace std;
#include<string.h>
#define MAX 100


//������ϵ�˽ṹ��
struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};

//����ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person PersonArray[MAX];
	int m_size;
};


//��ʾ�˵�
void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

//�����ϵ��
void addPerson(Addressbooks * abs) {
	if (abs->m_size > MAX) {
		cout << "������ӵ�������" << endl;;
	}
	else {
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->PersonArray[abs->m_size].name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1--��" << "0--Ů" <<endl;
		cin >> sex;
		abs->PersonArray[abs->m_size].sex = sex;

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->PersonArray[abs->m_size].age = age;

		string phone;
		cout << "��������ϵ�绰" << endl;
		cin >> phone;
		abs->PersonArray[abs->m_size].phone = phone;

		string addr;
		cout << "�������ַ" << endl;
		cin >> addr;
		abs->PersonArray[abs->m_size].addr = addr;

		abs->m_size ++;
		cout << "�����ϵ�˳ɹ�" << endl;
		system("pause");
		system("cls");
	}
}

//��ʾ��ϵ��
void showPerson(Addressbooks abs) {
	if (abs.m_size < 1) {
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs.m_size; i++) {
			cout << "������" << abs.PersonArray[i].name << "\t";
			cout << "�Ա�" << (abs.PersonArray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs.PersonArray[i].age << "\t";
			cout << "��ϵ�绰��" << abs.PersonArray[i].phone << "\t";
			cout << "��ַ��" << abs.PersonArray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//������ϵ������λ��
int serchPerson(Addressbooks * abs,string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (name == abs->PersonArray[i].name) {
			return i;
		}
		else {
			cout << "��ϵ�˲�����" << endl;
			return -1;
		}
	}

}

//������ϵ��
void serchShowPerson(Addressbooks * abs) {
	cout << "������Ҫ���ҵ�����" << endl;
	string name;
	cin >> name;
	int result = 0;
	result = serchPerson(abs, name);
	if (result != -1) {
		cout << "������" << abs->PersonArray[result].name << "\t";
		cout << "�Ա�" << (abs->PersonArray[result].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->PersonArray[result].age << "\t";
		cout << "��ϵ�绰��" << abs->PersonArray[result].phone << "\t";
		cout << "��ַ��" << abs->PersonArray[result].addr << endl;
	}
	system("pause");
}

//ɾ����ϵ��
void deletPerson(Addressbooks * abs) {
	cout << "������Ҫɾ��������" << endl;
	string name;
	cin >> name;
	int result = 0;
	result = serchPerson(abs,name);
	if (result !=-1) {
		for (int i = result; i < abs->m_size; i++) {
			abs->PersonArray[i] = abs->PersonArray[i + 1];		//�߼��ϵ�ɾ��
			abs->m_size --;
		}
		cout << "�ɹ�ɾ��ָ����ϵ��" << endl;
	}
	else {
		cout << "��ϵ�˲�����" << endl;
	}
	system("pause");
}

//�޸���ϵ��
void changePerson(Addressbooks * abs) {
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int result = 0;
	result = serchPerson(abs, name);
	if (result != -1) {
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->PersonArray[result].name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1--��" << "0--Ů" << endl;
		cin >> sex;
		abs->PersonArray[result].sex = sex;

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->PersonArray[result].age = age;

		string phone;
		cout << "��������ϵ�绰" << endl;
		cin >> phone;
		abs->PersonArray[result].phone = phone;

		string addr;
		cout << "�������ַ" << endl;
		cin >> addr;
		abs->PersonArray[result].addr = addr;

		cout << "�޸���ϵ�˳ɹ�" << endl;
	}
	else {
		cout << "��ϵ�˲�����" << endl;
	}
	cout << "�ɹ�ɾ����ϵ��" << endl;
	system("pause");
}

//ɾ��������ϵ��
void deleteAllPerson(Addressbooks * abs) {
	abs->m_size = 0;		//�ýṹ������ĳ���Ϊ0�����ʲ�������
}

int main() {

	//��ʼ���ṹ��
	Addressbooks abs;
	abs.m_size = 0;

	int select = 0;
	while (true)
	{
		system("cls");

		//��ʾ�˵�
		showMenu();

		cout << "��������ѡ�˵�������" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);		//�����ϵ��
			break;
		case 2:
			showPerson(abs);		//��ʾ��ϵ��
			break;
		case 3:
			deletPerson(&abs);		//ɾ����ϵ��
			break;
		case 4:
			serchShowPerson(&abs);		//������ϵ��
			break;
		case 5:
			changePerson(&abs);		  //�޸���ϵ��
			break;
		case 6:
			deleteAllPerson(&abs);			//ɾ��������ϵ��
			break;
		default:
		{
			cout << "�˳��˵��ɹ�" << endl;
			system("pause");
			return 0;
		}
			break;
		}
	}

	system("pause");
	return 0;
}