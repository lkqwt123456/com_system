#include<iostream>
using namespace std;
#include<string.h>
#define MAX 100


//定义联系人结构体
struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};

//定义通讯录结构体
struct Addressbooks
{
	struct Person PersonArray[MAX];
	int m_size;
};


//显示菜单
void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}

//添加联系人
void addPerson(Addressbooks * abs) {
	if (abs->m_size > MAX) {
		cout << "超过添加的总人数" << endl;;
	}
	else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->PersonArray[abs->m_size].name = name;

		int sex;
		cout << "请输入性别" << endl;
		cout << "1--男" << "0--女" <<endl;
		cin >> sex;
		abs->PersonArray[abs->m_size].sex = sex;

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->PersonArray[abs->m_size].age = age;

		string phone;
		cout << "请输入联系电话" << endl;
		cin >> phone;
		abs->PersonArray[abs->m_size].phone = phone;

		string addr;
		cout << "请输入地址" << endl;
		cin >> addr;
		abs->PersonArray[abs->m_size].addr = addr;

		abs->m_size ++;
		cout << "添加联系人成功" << endl;
		system("pause");
		system("cls");
	}
}

//显示联系人
void showPerson(Addressbooks abs) {
	if (abs.m_size < 1) {
		cout << "当前通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < abs.m_size; i++) {
			cout << "姓名：" << abs.PersonArray[i].name << "\t";
			cout << "性别：" << (abs.PersonArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs.PersonArray[i].age << "\t";
			cout << "联系电话：" << abs.PersonArray[i].phone << "\t";
			cout << "地址：" << abs.PersonArray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找联系人所在位置
int serchPerson(Addressbooks * abs,string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (name == abs->PersonArray[i].name) {
			return i;
		}
		else {
			cout << "联系人不存在" << endl;
			return -1;
		}
	}

}

//查找联系人
void serchShowPerson(Addressbooks * abs) {
	cout << "请输入要查找的姓名" << endl;
	string name;
	cin >> name;
	int result = 0;
	result = serchPerson(abs, name);
	if (result != -1) {
		cout << "姓名：" << abs->PersonArray[result].name << "\t";
		cout << "性别：" << (abs->PersonArray[result].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->PersonArray[result].age << "\t";
		cout << "联系电话：" << abs->PersonArray[result].phone << "\t";
		cout << "地址：" << abs->PersonArray[result].addr << endl;
	}
	system("pause");
}

//删除联系人
void deletPerson(Addressbooks * abs) {
	cout << "请输入要删除的姓名" << endl;
	string name;
	cin >> name;
	int result = 0;
	result = serchPerson(abs,name);
	if (result !=-1) {
		for (int i = result; i < abs->m_size; i++) {
			abs->PersonArray[i] = abs->PersonArray[i + 1];		//逻辑上的删除
			abs->m_size --;
		}
		cout << "成功删除指定联系人" << endl;
	}
	else {
		cout << "联系人不存在" << endl;
	}
	system("pause");
}

//修改联系人
void changePerson(Addressbooks * abs) {
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int result = 0;
	result = serchPerson(abs, name);
	if (result != -1) {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->PersonArray[result].name = name;

		int sex;
		cout << "请输入性别" << endl;
		cout << "1--男" << "0--女" << endl;
		cin >> sex;
		abs->PersonArray[result].sex = sex;

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->PersonArray[result].age = age;

		string phone;
		cout << "请输入联系电话" << endl;
		cin >> phone;
		abs->PersonArray[result].phone = phone;

		string addr;
		cout << "请输入地址" << endl;
		cin >> addr;
		abs->PersonArray[result].addr = addr;

		cout << "修改联系人成功" << endl;
	}
	else {
		cout << "联系人不存在" << endl;
	}
	cout << "成功删除联系人" << endl;
	system("pause");
}

//删除所有联系人
void deleteAllPerson(Addressbooks * abs) {
	abs->m_size = 0;		//让结构体数组的长度为0，访问不到数据
}

int main() {

	//初始化结构体
	Addressbooks abs;
	abs.m_size = 0;

	int select = 0;
	while (true)
	{
		system("cls");

		//显示菜单
		showMenu();

		cout << "请输入所选菜单的数字" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);		//添加联系人
			break;
		case 2:
			showPerson(abs);		//显示联系人
			break;
		case 3:
			deletPerson(&abs);		//删除联系人
			break;
		case 4:
			serchShowPerson(&abs);		//查找联系人
			break;
		case 5:
			changePerson(&abs);		  //修改联系人
			break;
		case 6:
			deleteAllPerson(&abs);			//删除所有联系人
			break;
		default:
		{
			cout << "退出菜单成功" << endl;
			system("pause");
			return 0;
		}
			break;
		}
	}

	system("pause");
	return 0;
}