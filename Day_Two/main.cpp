#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Find the Factorial of a number
size_t factorial(size_t n)
{
    if(n==1||n==0)
        return 1;
    return n*factorial(n-1);
}

// Binary Search Algorithm
int binarySearch(int array[], int size, int target)
{
    int left = 0, right = -1;
    while(left<=right)
    {
        int mid = left +(right-left)/2;
        if(array[mid]==target)
            return mid;
        else if(array[mid]<target)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}


// Lets Look into Nodes and LinkedLists

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next = nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int val)
    {
        Node* newNode = new Node(val);
        if(!head)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node* temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void deleteNode(int val)
    {
        if(!head)
        {
            return;
        }
        if(head->data==val)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while(temp->next && temp->data != val)
            temp = temp->next;
        if(temp->next)
        {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
};


//Implement tree traversal algorithms like inorder, preorder, and postorder traversal.
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void InorderTraversal(TreeNode* root)
{
    if(!root) return;
    InorderTraversal(root->left);
    cout<<root->val<<" ";
    InorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root){
    if(!root) return;
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root){
    if(!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->val<<" ";
}


int main()
{
    std::cout<<"//======================= Fibonacii Testing ==========================//"<<endl;
    size_t terms = 5;
    cout<<"The factorial of "<<terms<<" is:"<<factorial(terms)<<endl;

    std::cout<<"// ======================= Binary Search ============================//"<<endl;
    int arr[] = {1,2,3,4,5,6,7,8,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearch(arr, size,terms);
    if(index !=-1)
        cout<<"Value not found at index:"<<index<<endl;
    else
        cout<<"Element not found" <<endl;

    std::cout<<"//========================= Binary Search Using Ranges ================//"<<endl;
    std::vector<int> v(arr,arr+9);

    // Ensure the array is in a sorted manner due to implementation approach
    std::sort(v.begin(), v.end());

    // Check if the target exists within the expected workspace- for default comparison
    std::cout<<"Looking for "<<terms;
    if(std::binary_search(v.begin(), v.end(),terms))
        std::cout <<"\n Found \n"; else std::cout<<"Not found.\n";
    std::cout<<endl;


    std::cout<<"//========================== Linked List Testings ========================//"<<endl;

    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);

    list.display();


    std::cout<<"//=========================== Tree Traversal===============================//"<<endl;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(6);

    cout<<"Inorder Traversal: ";
    InorderTraversal(root);
    cout<<endl;

    cout<<"Preorder Traversal: ";
    preorderTraversal(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postorderTraversal(root);
    cout<<endl;


}
