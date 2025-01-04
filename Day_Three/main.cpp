#include <iostream>
#include<vector>
#include <unordered_set>

using namespace std;

// Some Global Variable
const int MAX_SIZE = 100;


// Implement a stack data structure and its basic operations (push, pop, isEmpty, peek).

class Stack{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack(){
        top = -1;
    }

    bool isEmpty(){
        return top ==-1;
    }

    void push(int value)
    {
        if(top==MAX_SIZE-1)
        {
            std::cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = value;
    }

    void pop(){
        if(isEmpty()){
            std::cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    int peek(){
        if(isEmpty()){
            std::cout<<"Stack is Empty"<<std::endl;
            return -1;
        }
        return arr[top];
    }
};

//Implement a queue data structure and its basic operations (enqueue, dequeue, isEmpty, peek).
class Queue{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue(){
        front=-1;
        rear=-1;
    }

    bool isEmpty(){
        return front==-1;
    }

    bool isFull(){
        return (rear+1)%MAX_SIZE == front;
    }

    void enqueue(int value){
        if(isFull()){
            std::cout<<"Queue Overflow"<<std::endl;
            return;
        }

        if(isEmpty()){
            front = rear = 0;
        }
        else
        {
            rear = (rear+1)%MAX_SIZE;
        }
        arr[rear] = value;
    }

    void dequeue(){
        if(isEmpty()){
            std::cout<<"Queue UnderFlow"<<std::endl;
            return;
        }
        if(front==rear)
            front = rear = -1;
        else
            front = (front+1)%MAX_SIZE;
    }

    int peek(){
        if(isEmpty()){
            std::cout<<"Queue is empty"<<std::endl;
            return -1;
        }
        return arr[front];
    }

};

//Given an array containing n distinct numbers taken from 0, 1, 2, …, n, find the one that is missing from the array.

int findMissingNumber(vector<int>& nums)
{
    int n = nums.size();
    int total = (n+1)*n/2;
    for(int num:nums)
        total-=num;

    return total;
}

//Find the contiguous subarray with the largest sum in an array.
int maxSubArraySum(vector<int>& nums){
    int maxSum = INT_MIN,currentSum = 0;
    for(auto num:nums){
        currentSum = max(num,currentSum+num);
        maxSum = max(maxSum,currentSum);
    }
    return maxSum;
}

//Implement basic matrix operations like addition, multiplication, and transpose.

// Function to add two matrices
vector<vector<int>> matrixAddition(vector<vector<int>>& A,vector<vector<int>>&B){
    int m = A.size(), n = A[0].size();
    vector<vector<int>> result(m,vector<int>(n));
    for(int i=0; i<m; ++i)
    {
        for(int j = 0; j<n; j++)
            result[i][j] = A[i][j] + B[i][j];
    }
    return result;
}

// Function to multiply two matrices
vector<vector<int>> matrixMultiplication(vector<vector<int>>&A, vector<vector<int>>& B){
    int m1 = A.size(), n1 = A[0].size(), n2 = B[0].size();
    vector<vector<int>> result(m1,vector<int>(n2,0));
    for(int i = 0; i<m1; ++i)
        for(int j = 0; j<n2; ++j)
            for(int k = 0; k<n1;++k)
                result[i][j] +=A[i][k]*B[k][i];

    return result;
}

// Function to transpose Matrix
vector<vector<int>> matrixTranspose(vector<vector<int>>& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> result(n,vector<int>(m));
    for(int i = 0; i<m; ++i)
        for(int j = 0; j<n; ++j)
            result[j][i] = matrix[i][j];

    return result;
}


// Implement DFS algorithm for graph traversal.
class Graph{
    int V;
    vector<unordered_set<int>> adj;

public:
    Graph(int V):V(V), adj(V){}

    void addEdge(int u, int v){
        adj[u].insert(v);
        adj[v].insert(u); // For undirected graph
    }

    void DFSUtil(int v, vector<bool>& visited){
        visited[v] = true;
        std::cout<<v<<" ";
        for(auto u:adj[v]){
            if(!visited[u])
                DFSUtil(u,visited);
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};



int main()
{
    std::cout<<"======================= Stack Working =========================="<<endl;

    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout<<"Top Element: "<<stack.peek()<<std::endl;
    stack.pop();
    std::cout<<"Top element after popping:"<<stack.peek() <<std::endl;

    std::cout<<"======================= Queue Working =========================="<<endl;

    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(4);

    std::cout<<"Front Element:"<<queue.peek()<<std::endl;
    queue.dequeue();
    queue.dequeue();
    std::cout<<"Front Element after Dequeue:"<<queue.peek()<<std::endl;

    std::cout<<"======================= Missing Number =========================="<<endl;

    vector<int> nums = {3,1,0,4,6,2};
    std::cout<<"Missing number: "<< findMissingNumber(nums)<<std::endl;

    std::cout<<"======================= Array Size Comparison =========================="<<endl;

    vector<int> nums1 ={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout<<"Maximum Subarray Sum: "<< maxSubArraySum(nums1)<<std::endl;

    std::cout<<"========================Matrix Operations =============================="<<std::endl;

    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    cout << "Matrix A:" << endl;
    for (const auto& row : A) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    cout << "Matrix B:" << endl;
    for (const auto& row : B) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    vector<vector<int>> sum = matrixAddition(A, B);
    cout << "Matrix A + B:" << endl;
    for (const auto& row : sum) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    vector<vector<int>> product = matrixMultiplication(A, B);
    cout << "Matrix A * B:" << endl;
    for (const auto& row : product) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    vector<vector<int>> transposeA = matrixTranspose(A);
    cout << "Transpose of Matrix A:" << endl;
    for (const auto& row : transposeA) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    vector<vector<int>> transposeB = matrixTranspose(B);
    cout << "Transpose of Matrix B:" << endl;
    for (const auto& row : transposeB) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    std::cout<<"======================== DFS Algorithm =============================="<<std::endl;
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);

    std::cout<<" Depth First Traversal starting from vertex 0: ";
    g.DFS(1);
    std::cout<<endl;

}
