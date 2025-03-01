#include<bits/stdc++.h>
using namespace std;
#define max 4//�����ϵ����
struct person {//��ϵ�˽ṹ��
	string name;//����
	int sex;//�Ա�
	int age;//����
	string num;//�绰
};
struct notebook {//ͨѶ¼�ṹ��
	person person_arr[max];//ͨѶ¼��ϵ������
	int person_num;//��ϵ����
};
// �������ݵ��ļ�
void saveToFile(notebook* txl, string& filename) {
	/*filename ʹ�����ã�

filename ��һ�� std::string ����ʹ�����ÿ��Ա��⸴���ַ�����

�����������������ȷ��ʾ filename ��һ�����������*/
	ofstream outFile(filename);
	/* ���ļ�ofstream��

	   �� C++ ��׼���е�һ���࣬��ʾ����ļ�����Output File Stream����

		   ���ڽ�����д���ļ���*/
	if (!outFile) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	for (int i = 0; i < txl->person_num; i++) {
		outFile << txl->person_arr[i].name << " "//д���ļ�
			<< txl->person_arr[i].sex << " "
			<< txl->person_arr[i].age << " "
			<< txl->person_arr[i].num << endl;
	}

	outFile.close();//�ر��ļ�
	cout << "�����ѱ��浽�ļ���" << filename << endl;
}
// ���ļ���������
void loadFromFile(notebook* txl, string& filename) {
	ifstream inFile(filename); // ���ļ�
	if (!inFile) {
		cerr << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	while (inFile >> txl->person_arr[txl->person_num].name
		>> txl->person_arr[txl->person_num].sex
		>> txl->person_arr[txl->person_num].age
		>> txl->person_arr[txl->person_num].num) {
		txl->person_num++;
		if (txl->person_num >= max) {
			break; // �ﵽ�������
		}
	}

	inFile.close();
	cout << "�����Ѵ��ļ����أ�" << filename << endl;
}
//�˵�
void menu() {
	cout << "***************************" << endl;
	cout << "*******1�������ϵ��*******" << endl;
	cout << "*******2����ʾ��ϵ��*******" << endl;
	cout << "*******3��ɾ����ϵ��*******" << endl;
	cout << "*******4��������ϵ��*******" << endl;
	cout << "*******5���޸���ϵ��*******" << endl;
	cout << "*******6�������ϵ��*******" << endl;
	cout << "*******0���˳�ͨѶ¼*******" << endl;
	cout << "***************************" << endl;
	cout << endl;
}
//�����ϵ��
void add_person(notebook* txl) {
	string filename = "notebook.txt"; // �ļ���
	while (true) {
		char a = 'n';
		if (txl->person_num == max) {
			cout << "ͨѶ¼���������ʧ��" << endl;
			system("pause");
			system("cls");
			return;
		}//�ж��Ƿ�����
		else {
			cout << "������������" << endl;
			cin >> txl->person_arr[txl->person_num].name;
			cout << "�������Ա�(1Ϊ���ԣ�0ΪŮ��)" << endl;
			while (true) {
				cin >> txl->person_arr[txl->person_num].sex;
				if (txl->person_arr[txl->person_num].sex == 1 || txl->person_arr[txl->person_num].sex == 0) {
					break;
				}
				else cout << "�����Ա���������������" << endl;
			}//�ж��Ա��ʽ�Ƿ�����
			cout << "���������䣺" << endl;
			cin >> txl->person_arr[txl->person_num].age;
			cout << "������绰��" << endl;
			cin >> txl->person_arr[txl->person_num].num;
			txl->person_num++;
			// ÿ����Ӻ󱣴����ݵ��ļ�
			saveToFile(txl, filename);
			cout << "��ӳɹ����Ƿ������ӣ���y/n��" << endl;
			cin >> a;
			if (a == 'n') {
				cout << "���˳�" << endl;
				break; // �˳�ѭ��
			}
		}
	}
	system("pause");
	system("cls");
}
//��ʾ��ϵ��
void show_person(notebook txl) {
	if (txl.person_num != 0) {
		for (int i = 0; i < txl.person_num; i++) {
			cout << "��" << i + 1 << "����¼��" << endl
				<< "	������" << txl.person_arr[i].name << endl
				<< "	" << (txl.person_arr[i].sex == 1 ? "�Ա���" : "�Ա�Ů") << endl//�Ա�ת��
				<< "	���䣺" << txl.person_arr[i].age << endl
				<< "	�绰��" << txl.person_arr[i].num << endl;
			cout << endl;
		}
	}
	else cout << "��ǰͨѶ¼Ϊ�գ�������ӣ�" << endl;
	system("pause");
	system("cls");
}
//������ϵ��
int search_person(notebook* txl, string name) {
	for (int i = 0; i < txl->person_num; i++) {
		if (txl->person_arr[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
//������ϵ��
void find_person(notebook* txl) {
	char a;
	string name;
	while (true) {
		cout << "������Ҫ���ҵ�������" << endl;
		cin >> name;
		int  i = search_person(txl, name);
		if (i != -1) {
			cout << "���ҵ�����ϵ�ˣ����Ϊ" << i + 1 << endl
				<< "	������" << txl->person_arr[i].name << endl
				<< "	" << (txl->person_arr[i].sex == 1 ? "�Ա���" : "�Ա�Ů") << endl//�Ա�ת��
				<< "	���䣺" << txl->person_arr[i].age << endl
				<< "	�绰��" << txl->person_arr[i].num << endl;
			cout << endl;
		}
		else cout << "δ�ҵ�����ϵ��" << endl;
		cout << "�Ƿ�������ң���y/n��" << endl;
		cin >> a;
		if (a == 'n') {
			cout << "���˳�" << endl;
			break; // �˳�ѭ��
		}
	}
	system("pause");
	system("cls");
}
//ɾ����ϵ��
void delete_person(notebook* txl) {
	string filename = "notebook.txt";
	string name;
	char a, b;
	while (true) {
		cout << "������Ҫɾ��������:" << endl;
		cin >> name;
		int i = search_person(txl, name);
		if (i == -1)
			cout << "���޴���" << endl;
		else {
			cout << "���ҳɹ���ȷ��ɾ������y/n��" << endl;
			cin >> a;
			if (a == 'y') {
				txl->person_arr[i] = txl->person_arr[txl->person_num - 1];//���һ�����ݸ���ǰһ��
				txl->person_num--;
				cout << "��ɾ����ϵ��" << name << ",ʣ���¼" << txl->person_num << "��" << endl;
				saveToFile(txl, filename);
			}
		}
		cout << "�Ƿ����ɾ��? (y/n)" << endl;
		cin >> b;
		if (b == 'n') {
			cout << "���˳�" << endl;
			break; // �˳�ѭ��
		}
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void mod_person(notebook* txl) {
	string filename = "notebook.txt";
	string name;
	char b;
	int a;
	while (true) {
		cout << "������Ҫ�޸ĵ���ϵ������:" << endl;
		cin >> name;
		int i = search_person(txl, name);
		if (i == -1)
			cout << "���޴���" << endl;
		else {
			cout << "��" << i + 1 << "����¼��" << endl
				<< "	������" << txl->person_arr[i].name << endl
				<< "	" << (txl->person_arr[i].sex == 1 ? "�Ա���" : "�Ա�Ů") << endl//�Ա�ת��
				<< "	���䣺" << txl->person_arr[i].age << endl
				<< "	�绰��" << txl->person_arr[i].num << endl;
				cout << "���ҳɹ�����ѡ���޸���" << endl
					<< "1������" << endl
					<< "2���Ա�" << endl
					<< "3������" << endl
					<< "4���绰" << endl;
				cin >> a;
				switch (a) {//ѡ���֧
				case 1:
					cout << "�������޸ĺ������" << endl;
					cin >> txl->person_arr[i].name;
					cout << "�޸ĳɹ�" << endl;
					break;
				case 2:
					cout << "�������޸ĺ���Ա�" << endl;
					cin >> txl->person_arr[i].sex;
					cout << "�޸ĳɹ�" << endl;
					break;
				case 3:
					cout << "�������޸ĺ������" << endl;
					cin >> txl->person_arr[i].age;
					cout << "�޸ĳɹ�" << endl;
					break;
				case 4:
					cout << "�������޸ĺ�ĵ绰" << endl;
					cin >> txl->person_arr[i].num;
					cout << "�޸ĳɹ�" << endl;
					break;
				default:cout << "������Ч������������" << endl;
				}
				saveToFile(txl, filename);
			}
		cout << "�Ƿ�����޸�? (y/n)" << endl;
		cin >> b;
		if (b == 'n') {
			cout << "���˳�" << endl;
			break; // �˳�ѭ��
		}

		}
	system("pause");
	system("cls");
	}
//�����ϵ��	
void clean_person(notebook* txl) {
	string filename = "notebook.txt";
	char b;
	cout << "ȷ��Ҫ���������ϵ���𣿴˲������ɻָ�����y/n����" << endl;
	cin >> b;
	if (b == 'y' ) {
		txl->person_num = 0; // ������ϵ������
		saveToFile(txl, filename); // ��������ݵ��ļ�
		cout << "������ϵ������ա�" << endl;
	}
	else {
		cout << "������ȡ����" << endl;
	}
	system("pause");
	system("cls");
}

int main() {
	notebook txl;
	string filename = "notebook.txt";
	txl.person_num = 0; // ������ϵ������
	loadFromFile(&txl, filename);
	int select = 0;

	while (true) {
		menu();//��ʾ�˵�
		cout << "��ѡ����Ҫ���еĲ���:" << endl;
		cin >> select;
		switch (select) {//ѡ���֧
		case 1://�����ϵ��
			add_person(&txl);
			break;
		case 2://��ʾ��ϵ��
			show_person(txl);
			break;
		case 3://ɾ����ϵ��
			delete_person(&txl);
			break;
		case 4://������ϵ��
			find_person(&txl);
			break;
		case 5://�޸���ϵ��
			mod_person(&txl);
			break;
		case 6://�����ϵ��
			clean_person(&txl);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:cout << "������Ч������������" << endl;
			cout << endl;
		}
	}
}