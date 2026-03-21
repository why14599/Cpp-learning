#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person {
private:
	std::string name;
	std::string sex;
	int age;
	std::string phone;
	std::string address;
public:
	Person() {};
	Person(string name, string sex, int age, string phone, string address) {
		this->name = name;
		this->sex = sex;
		this->age = age;
		this->phone = phone;
		this->address = address;
	}
	
	void get_Info() {
		cout << "姓名:" << this->name << '\t'
			<< "性别" << sex << '\t'
			<< "年龄" << age << '\t'
			<< "电话" << phone << '\t'
			<< "住址" << address << endl;
	}

	string get_Name() {
		return name;
	}

	int modify_Name(string afterName) {
		this->name = afterName;
		return 1;
	}
};

Person createPerson() {
	string name;
	string sex, phone, address;
	int age;
	cout << "输入姓名" << endl;
	cin >> name;
	cout << "性别" << endl;
	cin >> sex;
	cout << "年龄" << endl;
	cin >> age;
	cout << "电话" << endl;
	cin >> phone;
	cout << "住址" << endl;
	cin >> address;

	return Person(name, sex, age, phone, address);
}
int main() {
	vector<unique_ptr<Person>> dataPositon;
	while (1) {
		cout << "0:退出;1:添加;2:显示;3:删除;4:查找;5:修改;6:清空" << endl;
		int choice;
		cin >> choice;
		if (choice == 0) {
			cout << "退出" << endl;
			return 0;
		}
		if (choice == 1) {
			Person* data = new Person();
			*data = createPerson();
			dataPositon.push_back(unique_ptr<Person>(data));
		}
		if (choice == 2) {
			int x;
			cin >> x;
			int n = min(x, (int)dataPositon.size());
			for (int i = 0; i < n; i++) {
				dataPositon[i]->get_Info();  // 智能指针用 ->
			}
		}
		if (choice == 3) {
			string deleteName;
			cout << "delete name:" << endl;
			cin >> deleteName;
			for (int i = 0; i < dataPositon.size(); i++) {
				if (!deleteName.compare(dataPositon[i]->get_Name())) {
					dataPositon.erase(dataPositon.begin() + i);
					break;
				}
			}
		 }
		if (choice == 4) {
			string wantedName;
			cout << "wanted name:" << endl;
			cin >> wantedName;
			for (int i = 0; i < dataPositon.size(); i++) {
				if (!wantedName.compare(dataPositon[i]->get_Name())) {
					dataPositon[i]->get_Info();
					break;
				}
			}
		}
		if (choice == 5) {
			string nameBefore, nameAfter;
			cout << "replice name:" << endl;
			cin >> nameBefore>>nameAfter;
			for (int i = 0; i < dataPositon.size(); i++) {
				if (!nameBefore.compare(dataPositon[i]->get_Name())) {
					dataPositon[i]->modify_Name(nameAfter);
					break;
				}
			}
		}
		if (choice == 6) {
			dataPositon.clear();
		}
	}
	return 0;
}

