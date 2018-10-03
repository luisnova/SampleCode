#include <stdio.h>
#include <stdlib.h> 

template <class T>
class Element 
{
    T value;
    Element *next;
};

template <class T>
class Queue 
{
    private:
        Element<T> *front;
        Element<T> *back;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(T n);
        T dequeue();
};

Queue::Queue() 
{
    front = NULL;
    back = NULL;
}
 
Queue::~Queue() 
{
    delete front;
}

void Queue::enqueue(T data) 
{
    Node<T> *temp = new Element<T>();
    temp->value = data;
    temp->next = NULL;
    if(front == NULL)
        front = temp;
    else
        back->next = temp;
    back = temp;
}

T Queue::dequeue() {
    T v;
    if (front == NULL)
    {
      cout<<"\nQueue is Emtpty\n";
    }
    else
    {
      v = front->value;
      front = front->next;
    }
    return v;
}
 
bool Queue::isEmpty() 
{
    return (front == NULL);
}

template <class T>
class Node 
{
    T value;
    Node *left;
    Node *right;
};

template <class T>
class Bin_tree 
{
    private:
      Node<T> *root;
      
    public:
        Bin_tree() { root = NULL }
        ~Bin_tree() {}
        void AddNode(T data);
        void BFS();
};

void Bin_tree::AddNode(T data)
{
  Node<T> *newNode = new Node<T> ();
  newNode->value = data;
  /* TODO: add to tree */
}

void Bin_tree::BFS() 
{
  Queue<T> Q;
  if (root == NULL)
    return;
 
  Q.enqueue(root);
  cout << root->value << " \n";

  while (!Q.isEmpty()) 
  {
    Node *node = Q.dequeue();
    if (node->left != NULL)
    {
      Q.enqueue(node->left);
      cout << node->left->value << " \n";
    }
    if (node->right != NULL)
    {
      Q.enqueue(node->right) 
      cout << node->right->value << " \n";
    }
  }
  cout << endl;
}

int main(int argc, const char* argv[])
{
  Bin_tree<int> tree;
    
  for (int i=2; i<=argc; i++)
    tree.Add( atoi( argv[i] ) );

  tree.BFS();
}
