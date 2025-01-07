#include <iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include <sstream>
#include <list>
#include<unordered_map>

using namespace std;

// Implement BFS algorithm for graph traversal.

class Graph{
    int V;
    vector<unordered_set<int>> adj;

public:
    Graph(int V): V(V), adj(V){}

    void addEdge(int u, int v)
    {
        adj[u].insert(v);
        adj[v].insert(u); // For unidirected Graph
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            cout<<v<<" ";
            for(int u:adj[v]){
                if(!visited[u]){
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
};


// Write a function to tokenize a string based on a delimiter.
std::vector<string> tokenizeString(const string & str, char delimiter){
    std::vector<string> tokens;
    std::stringstream ss(str);
    string token;
    while(getline(ss,token,delimiter))
        tokens.push_back(token);
    return tokens;
}

// Find the duplicate element in an array of integers where each element is between 1 and n, with n being the length of the array.
int findDuplicate(vector<int>& nums){
    std::unordered_set<int> seen;
    for(int num:nums){
        if(seen.find(num)!=seen.end())
            return num;
        seen.insert(num);
    }
    return -1; // No duplicates
}

// Reverse a linked list iteratively and recursively.

class Node{
public:
    int data;
    Node* next;
    Node(int val):data(val), next(nullptr){}
};

Node* reverseIterative(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    while(current !=nullptr){
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}


Node* reverseRecursive(Node* head){
    if(!head||!head->next) return head;
    Node* reversed = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return reversed;
}


void display(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<endl;
}

//Implement an LRU (Least Recently Used) cache using appropriate data structures.
class LRUCache{
    list<int> cache;
    unordered_map<int,list<int>::iterator> mp;
    int capacity;

public:
    LRUCache(int capacity):capacity(capacity){}

    void refer(int page){
        if(mp.find(page)==mp.end()){
            if(cache.size()==capacity){
                int last = cache.back();
                cache.pop_back();
                mp.erase(last);
            }
        }
        else
            cache.erase(mp[page]);
        cache.push_front(page);
        mp[page] = cache.begin();
    }

    void display(){
        for(auto it = cache.begin(); it!=cache.end();++it)
            std::cout<<(*it)<<" ";
        std::cout<<std::endl;
    }
};


int main()
{
    std::cout<<"===========================================                         BFS Algorithm         ============================================"<<std::endl;
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);

    std::cout << "Breadth First Traversal starting vertex 0.: ";
    g.BFS(0);
    std::cout<<std::endl;

    std::cout<<"===========================================      Tokenizing a string Based on Delimiters  ============================================"<<std::endl;
    std::string input = "Hello,World,This,is,C++,Programming";
    char delimiter = ',';
    std::vector<string> tokens = tokenizeString(input,delimiter);
    std::cout<<"Tokens:";
    for(const string& token:tokens)
        std::cout<<" "<<token;
    std::cout<<endl;

    std::cout<<"===========================================                  Finding Duplicate           ============================================"<<std::endl;

    std::vector<int> nums = {1,2,4,32,1,3};
    std::cout<<"Duplicate element: "<<findDuplicate(nums)<<std::endl;

    std::cout<<"===========================================   Linked List Iteration/Recursive             ============================================"<<std::endl;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    std::cout<<"Original List: ";
    display(head);

    // Reversing Iteratively
    head = reverseIterative(head);
    std::cout<<"Reversed list(iterative List):";
    display(head);

    //Reversing Recursively
    head = reverseRecursive(head);
    cout<<"Reversed List (Recursive List): ";
    display(head);

    std::cout<<"===========================================                   Least Recently Used           ============================================"<<std::endl;
    LRUCache cache(4);
    cache.refer(1);
    cache.refer(2);
    cache.refer(3);
    cache.refer(1);
    cache.refer(4);
    cache.refer(5);
    std::cout<<"LRU Cache: ";
    cache.display();

}
