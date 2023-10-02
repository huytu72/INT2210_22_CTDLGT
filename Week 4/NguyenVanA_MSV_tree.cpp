#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node* sibling;
public:
    Node() {
        this->data = 0;
        this->fatherNode = NULL;
        this->firstChild = NULL;
        this->sibling = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Node(int data, Node* parent){
        this->data = data;
        this->fatherNode = parent;
        this->firstChild = NULL;
        this->sibling = NULL;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        // ...
        this->root = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết

    bool existNode(Node* tmp, int data) {
        if (tmp) {
            if (tmp -> data == data) return true;
            Node* p = find(node -> firstChild, data);
            if (p) return true;
            p = find(node -> sibling, data);
            if (p) return true;
        }
        return false;
    }

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data){
        if (root == NULL) root = new Node(father, root);
        Noe* fatherNode = new(father, root);
        if (!existNode(root, father)) return false;
        if (fatherNode->firstChild->data == data) return false;
        return true;
    };

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data);

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->data << " ";
        preorder()
    };

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(node* t) {
        if (t != NULL) {
            cout << t->data << " ";
            postorder(t->firstChild);
            postorder(t->sibling);
        }
    };

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree();

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree();

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree();

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder();

    // Hàm trả về độ cao của cây
    int height();

    // Hàm trả về độ sâu của một Node
    int depth(int data);

    // Hàm đếm số lượng lá
    int numOfLeaves();

    // Hàm trả về Node có giá trị lớn nhất
    int findMax();

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild();
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại

    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}
