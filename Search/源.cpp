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
		cout << "恭喜你成功找到答案";
	}
	else {
		cout << "该序列中没有你想要的数据";
	}
}
//此处是任务一的代码。已经完成
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
};//类中结点的结构体
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
		cout << "该数据不在树中，请重新输入" << endl;
	}
	else {
		if (value < p->data) {
			myDelete(value, p->left);
		}
		else if (value > p -> data) {
			myDelete(value, p->right);
		}//下面都已经是相等的情况了
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
bool BST::insert(const int value, BSTNode*& p) {//不加引用符号root不会进行赋值，这是为什么
	if (p == NULL) {
		p = new BSTNode(value);
		if (p == NULL) {
			cerr << "OUT OF SPACE" << endl;
			exit(1);
		}
		cout << "二叉搜索树中没有该数据，已经为该数据建立结点 "<<endl;
		return false;
	}
	else if (value < p->data) {
		insert(value, p->left);
	}
	else if (value > p->data) {
		insert(value, p->right);
	}
	else {
		cout << value << "在这颗二叉搜索树上" << endl;
		return true;
	}
}
BST::BST() {
	//root = NULL;
	cout << "开始建树，请输入数据，输入-1即可停止建树" << endl;
	int x;
	cin >> x;
	while (x != -1) {
		insert(x, root);
		cin >> x;
	}
	cout << "已经完成二叉搜索树的初步建立，期待您的下次使用" << endl;
}
BSTNode* BST::find(int value,BSTNode *p) {
	//cout << "开始对您需要查找的数值进行查找" << endl;
	if (p == NULL) {
		cout << "查找的内容不在树中，请重新选择数据或者将该元素插入树中" << endl;
	}
	else if (value < p->data) {
		find(value,p->left);
	}
	else if (value > p->data) {
		find(value, p->right);
	}
	else {
		cout << "查找成功" << endl;
		return p;
	}
}

int main() {
	BST bst;
	bst.find(10, bst.getRoot());
	bst.myDelete(10, bst.getRoot());
	return 0;
}