#include <iostream>
#include<queue>

template<typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    Node(T d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// In Order Depth First Search(Left Root Right)
template<typename T>
void inOrderDFS(Node<T>* node){
    if(node == nullptr) return;

    inOrderDFS(node->left);
    std::cout<<node->data << " ";
    inOrderDFS(node->right);
}

// Pre-order DFS: Root Left Right
template<typename T>
void preOrderDFS(Node<T>* node) {
    if(node == nullptr) return;

    std::cout<< node->data << " ";
    preOrderDFS(node->left);
    preOrderDFS(node->right);
}

// Post Order DFS: Left Right Root
template<typename T>
void postOrderDFS(Node<T>* node )
{
    if(node == nullptr) return;
    postOrderDFS(node->left);
    postOrderDFS(node->right);
    std::cout<< node->data <<" ";
}

// Breadth First Search Algorithm
template<typename T>
void BFS(Node<T>* root)
{
    if(root == nullptr) return;
    std::queue<Node<T>*> q;
    q.push(root);

    while(!q.empty()){
        Node<T>* node = q.front();
        q.pop();
        std::cout<<node->data << " ";
        if(node->left !=nullptr) q.push(node->left);
        if(node->right !=nullptr) q.push(node->right);
    }
}

template<typename T>
Node<T>* insert(Node<T>* root, int key){
    if(root == nullptr){
        root = new Node<int>(key);
        return root;
    }
    std::queue<Node<T>>* q;
    q.push(root);

    while(!q.empty()){
        Node<T>* temp = q.front();
    }
}

int main() {
    // Write C++ code here

    Node<int>* firstNode = new Node<int>(2);
    Node<int>* secondNode = new Node<int>(3);
    Node<int>* thirdNode = new Node<int>(4);
    Node<int>* fourthNode = new Node<int>(5);

    // Connecting the Nodes
    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;

    // DFS
    std::cout<< "In Order DFS: ";
    inOrderDFS(firstNode);
    std::cout<<std::endl;
    std::cout<< "Pre Order DFS: ";
    preOrderDFS(firstNode);
    std::cout<<std::endl;
    std::cout<< "Post Order DFS: ";
    postOrderDFS(firstNode);
    std::cout<<std::endl;

    std::cout<<" Level Order: ";
    BFS(firstNode);

    return 0;
}
