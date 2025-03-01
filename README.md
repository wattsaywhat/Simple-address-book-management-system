# 通讯录管理系统

---

## 项目简介
基于 B 站黑马程序员的通讯录管理系统，实现了一个简单的通讯录管理功能。  
该项目适合作为课程设计的结课作业，功能完整且代码清晰。

---

## 功能列表
1. **添加联系人**  
2. **显示联系人**  
3. **删除联系人**  
4. **查找联系人**  
5. **修改联系人**  
6. **清空联系人**  
0. **退出通讯录**

---

## 项目特点
- **多重验证**：增加了一些莫名其妙的验证逻辑（？），增强了系统的健壮性。  
- **文件读写**：实现了数据的持久化存储，通讯录数据可以反复使用。  

---

## 适用场景
- 课程设计（结课作业）  
- 初学者练手项目  
- 小型通讯录管理工具  

---

## 代码示例
```C++
# 示例代码片段
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
