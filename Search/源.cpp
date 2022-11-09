#include<iostream>
using namespace std;
int binarySearch(int arr[], int value,int end) {
	int low = 0;
	int high = end;
	int mid = (low + high) / 2;
	while (low <= high) {
		if (arr[mid] == value) {
			return mid;
		}
		else if (value < arr[mid]) {
			high = mid - 1;
		}
		else if (value > arr[mid]) {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	return -1;
}
void isFind(int answer) {
	if (answer >= 0) {
		cout << "��ϲ��ɹ��ҵ���";
	}
	else {
		cout << "��������û������Ҫ������";
	}
}
//�˴�������һ�Ĵ��롣�Ѿ����
//int main() {
//	int arr[] = { 8,11,19,23,27,33,45,55,67,98 };
//	int p=binarySearch(arr, 99, 9);
//	isFind(p);
//}
struct BSTNode {
	int data;
	BSTNode* left, * right;
	BSTNode(int a) { data = a;left = NULL;right = NULL; }
	int getData() { return data; }
};//���н��Ľṹ��
class BST {
public:
	bool insert(const int value, BSTNode* &p);
	BSTNode* find(int value, BSTNode* p);
	BST();
	bool myDelete(const int value, BSTNode* p);
	BSTNode* getRoot() {
		return root;
	}
private:
	BSTNode* root;
	int key = -1;
};
bool BST::myDelete(const int value, BSTNode* p) {
	if (p == NULL) {
		cout << "�����ݲ������У�����������" << endl;
	}
	else {
		if (value < p->data) {
			myDelete(value, p->left);
		}
		else if (value > p -> data) {
			myDelete(value, p->right);
		}//���涼�Ѿ�����ȵ������
		else if (p->left != NULL && p->right != NULL) {
			BSTNode* temp;
			temp = p->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}
			p->data = temp->data;
			myDelete(p->data, p->right);
		}
		else {
			BSTNode* temp2;
			temp2 = p;
			if (p->left == NULL) {
				p = p->right;
			}
			else {
				p = p->left;
			}
			delete temp2;
			return true;
		}
	}
}
bool BST::insert(const int value, BSTNode*& p) {//�������÷���root������и�ֵ������Ϊʲô
	if (p == NULL) {
		p = new BSTNode(value);
		if (p == NULL) {
			cerr << "OUT OF SPACE" << endl;
			exit(1);
		}
		cout << "������������û�и����ݣ��Ѿ�Ϊ�����ݽ������ "<<endl;
		return false;
	}
	else if (value < p->data) {
		insert(value, p->left);
	}
	else if (value > p->data) {
		insert(value, p->right);
	}
	else {
		cout << value << "����Ŷ�����������" << endl;
		return true;
	}
}
BST::BST() {
	//root = NULL;
	cout << "��ʼ���������������ݣ�����-1����ֹͣ����" << endl;
	int x;
	cin >> x;
	while (x != -1) {
		insert(x, root);
		cin >> x;
	}
	cout << "�Ѿ���ɶ����������ĳ����������ڴ������´�ʹ��" << endl;
}
BSTNode* BST::find(int value,BSTNode *p) {
	//cout << "��ʼ������Ҫ���ҵ���ֵ���в���" << endl;
	if (p == NULL) {
		cout << "���ҵ����ݲ������У�������ѡ�����ݻ��߽���Ԫ�ز�������" << endl;
	}
	else if (value < p->data) {
		find(value,p->left);
	}
	else if (value > p->data) {
		find(value, p->right);
	}
	else {
		cout << "���ҳɹ�" << endl;
		return p;
	}
}

int main() {
	BST bst;
	bst.find(10, bst.getRoot());
	bst.myDelete(10, bst.getRoot());
	return 0;
}