#include<bits/stdc++.h>
using namespace std;
#define max 4//最大联系人数
struct person {//联系人结构体
	string name;//姓名
	int sex;//性别
	int age;//年龄
	string num;//电话
};
struct notebook {//通讯录结构体
	person person_arr[max];//通讯录联系人数组
	int person_num;//联系人数
};
// 保存数据到文件
void saveToFile(notebook* txl, string& filename) {
	/*filename 使用引用：

filename 是一个 std::string 对象，使用引用可以避免复制字符串。

引用语义更清晰，明确表示 filename 是一个输入参数。*/
	ofstream outFile(filename);
	/* 打开文件ofstream：

	   是 C++ 标准库中的一个类，表示输出文件流（Output File Stream）。

		   用于将数据写入文件。*/
	if (!outFile) {
		cerr << "文件打开失败！" << endl;
		return;
	}

	for (int i = 0; i < txl->person_num; i++) {
		outFile << txl->person_arr[i].name << " "//写入文件
			<< txl->person_arr[i].sex << " "
			<< txl->person_arr[i].age << " "
			<< txl->person_arr[i].num << endl;
	}

	outFile.close();//关闭文件
	cout << "数据已保存到文件：" << filename << endl;
}
// 从文件加载数据
void loadFromFile(notebook* txl, string& filename) {
	ifstream inFile(filename); // 打开文件
	if (!inFile) {
		cerr << "文件打开失败！" << endl;
		return;
	}

	while (inFile >> txl->person_arr[txl->person_num].name
		>> txl->person_arr[txl->person_num].sex
		>> txl->person_arr[txl->person_num].age
		>> txl->person_arr[txl->person_num].num) {
		txl->person_num++;
		if (txl->person_num >= max) {
			break; // 达到最大容量
		}
	}

	inFile.close();
	cout << "数据已从文件加载：" << filename << endl;
}
//菜单
void menu() {
	cout << "***************************" << endl;
	cout << "*******1、添加联系人*******" << endl;
	cout << "*******2、显示联系人*******" << endl;
	cout << "*******3、删除联系人*******" << endl;
	cout << "*******4、查找联系人*******" << endl;
	cout << "*******5、修改联系人*******" << endl;
	cout << "*******6、清空联系人*******" << endl;
	cout << "*******0、退出通讯录*******" << endl;
	cout << "***************************" << endl;
	cout << endl;
}
//添加联系人
void add_person(notebook* txl) {
	string filename = "notebook.txt"; // 文件名
	while (true) {
		char a = 'n';
		if (txl->person_num == max) {
			cout << "通讯录已满，添加失败" << endl;
			system("pause");
			system("cls");
			return;
		}//判断是否已满
		else {
			cout << "请输入姓名：" << endl;
			cin >> txl->person_arr[txl->person_num].name;
			cout << "请输入性别：(1为男性，0为女性)" << endl;
			while (true) {
				cin >> txl->person_arr[txl->person_num].sex;
				if (txl->person_arr[txl->person_num].sex == 1 || txl->person_arr[txl->person_num].sex == 0) {
					break;
				}
				else cout << "输入性别有误，请重新输入" << endl;
			}//判断性别格式是否有误
			cout << "请输入年龄：" << endl;
			cin >> txl->person_arr[txl->person_num].age;
			cout << "请输入电话：" << endl;
			cin >> txl->person_arr[txl->person_num].num;
			txl->person_num++;
			// 每次添加后保存数据到文件
			saveToFile(txl, filename);
			cout << "添加成功，是否继续添加？（y/n）" << endl;
			cin >> a;
			if (a == 'n') {
				cout << "已退出" << endl;
				break; // 退出循环
			}
		}
	}
	system("pause");
	system("cls");
}
//显示联系人
void show_person(notebook txl) {
	if (txl.person_num != 0) {
		for (int i = 0; i < txl.person_num; i++) {
			cout << "第" << i + 1 << "条记录：" << endl
				<< "	姓名：" << txl.person_arr[i].name << endl
				<< "	" << (txl.person_arr[i].sex == 1 ? "性别：男" : "性别：女") << endl//性别转换
				<< "	年龄：" << txl.person_arr[i].age << endl
				<< "	电话：" << txl.person_arr[i].num << endl;
			cout << endl;
		}
	}
	else cout << "当前通讯录为空，请先添加！" << endl;
	system("pause");
	system("cls");
}
//搜索联系人
int search_person(notebook* txl, string name) {
	for (int i = 0; i < txl->person_num; i++) {
		if (txl->person_arr[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
//查找联系人
void find_person(notebook* txl) {
	char a;
	string name;
	while (true) {
		cout << "请输入要查找的姓名：" << endl;
		cin >> name;
		int  i = search_person(txl, name);
		if (i != -1) {
			cout << "已找到该联系人，编号为" << i + 1 << endl
				<< "	姓名：" << txl->person_arr[i].name << endl
				<< "	" << (txl->person_arr[i].sex == 1 ? "性别：男" : "性别：女") << endl//性别转换
				<< "	年龄：" << txl->person_arr[i].age << endl
				<< "	电话：" << txl->person_arr[i].num << endl;
			cout << endl;
		}
		else cout << "未找到该联系人" << endl;
		cout << "是否继续查找？（y/n）" << endl;
		cin >> a;
		if (a == 'n') {
			cout << "已退出" << endl;
			break; // 退出循环
		}
	}
	system("pause");
	system("cls");
}
//删除联系人
void delete_person(notebook* txl) {
	string filename = "notebook.txt";
	string name;
	char a, b;
	while (true) {
		cout << "请输入要删除的姓名:" << endl;
		cin >> name;
		int i = search_person(txl, name);
		if (i == -1)
			cout << "查无此人" << endl;
		else {
			cout << "查找成功，确认删除？（y/n）" << endl;
			cin >> a;
			if (a == 'y') {
				txl->person_arr[i] = txl->person_arr[txl->person_num - 1];//最后一个数据覆盖前一个
				txl->person_num--;
				cout << "已删除联系人" << name << ",剩余记录" << txl->person_num << "条" << endl;
				saveToFile(txl, filename);
			}
		}
		cout << "是否继续删除? (y/n)" << endl;
		cin >> b;
		if (b == 'n') {
			cout << "已退出" << endl;
			break; // 退出循环
		}
	}
	system("pause");
	system("cls");
}
//修改联系人
void mod_person(notebook* txl) {
	string filename = "notebook.txt";
	string name;
	char b;
	int a;
	while (true) {
		cout << "请输入要修改的联系人姓名:" << endl;
		cin >> name;
		int i = search_person(txl, name);
		if (i == -1)
			cout << "查无此人" << endl;
		else {
			cout << "第" << i + 1 << "条记录：" << endl
				<< "	姓名：" << txl->person_arr[i].name << endl
				<< "	" << (txl->person_arr[i].sex == 1 ? "性别：男" : "性别：女") << endl//性别转换
				<< "	年龄：" << txl->person_arr[i].age << endl
				<< "	电话：" << txl->person_arr[i].num << endl;
				cout << "查找成功，请选择修改项" << endl
					<< "1、姓名" << endl
					<< "2、性别" << endl
					<< "3、年龄" << endl
					<< "4、电话" << endl;
				cin >> a;
				switch (a) {//选择分支
				case 1:
					cout << "请输入修改后的姓名" << endl;
					cin >> txl->person_arr[i].name;
					cout << "修改成功" << endl;
					break;
				case 2:
					cout << "请输入修改后的性别" << endl;
					cin >> txl->person_arr[i].sex;
					cout << "修改成功" << endl;
					break;
				case 3:
					cout << "请输入修改后的年龄" << endl;
					cin >> txl->person_arr[i].age;
					cout << "修改成功" << endl;
					break;
				case 4:
					cout << "请输入修改后的电话" << endl;
					cin >> txl->person_arr[i].num;
					cout << "修改成功" << endl;
					break;
				default:cout << "输入无效，请重新输入" << endl;
				}
				saveToFile(txl, filename);
			}
		cout << "是否继续修改? (y/n)" << endl;
		cin >> b;
		if (b == 'n') {
			cout << "已退出" << endl;
			break; // 退出循环
		}

		}
	system("pause");
	system("cls");
	}
//清空联系人	
void clean_person(notebook* txl) {
	string filename = "notebook.txt";
	char b;
	cout << "确定要清空所有联系人吗？此操作不可恢复！（y/n）：" << endl;
	cin >> b;
	if (b == 'y' ) {
		txl->person_num = 0; // 重置联系人数量
		saveToFile(txl, filename); // 保存空数据到文件
		cout << "所有联系人已清空。" << endl;
	}
	else {
		cout << "操作已取消。" << endl;
	}
	system("pause");
	system("cls");
}

int main() {
	notebook txl;
	string filename = "notebook.txt";
	txl.person_num = 0; // 重置联系人数量
	loadFromFile(&txl, filename);
	int select = 0;

	while (true) {
		menu();//显示菜单
		cout << "请选择你要进行的操作:" << endl;
		cin >> select;
		switch (select) {//选择分支
		case 1://添加联系人
			add_person(&txl);
			break;
		case 2://显示联系人
			show_person(txl);
			break;
		case 3://删除联系人
			delete_person(&txl);
			break;
		case 4://查找联系人
			find_person(&txl);
			break;
		case 5://修改联系人
			mod_person(&txl);
			break;
		case 6://清空联系人
			clean_person(&txl);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:cout << "输入无效，请重新输入" << endl;
			cout << endl;
		}
	}
}