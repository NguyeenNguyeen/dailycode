#include <iostream>

using namespace std;

struct NODE
{
    int key;
    NODE* p_next;
};

struct List
{
    NODE* p_head;
    NODE* p_tail;
};

NODE* createNode(int data)
{
    NODE* n_node = new NODE;
    if (n_node == nullptr)
    {
        return nullptr;
    }
    
    n_node->key = data;
    n_node->p_next = nullptr;
    return n_node;
}

List* createList(NODE* p_node)
{
    List* L = new List;
    if (L == nullptr)
    {
        return nullptr;
    }
    L->p_head = L->p_tail = p_node;
    return L;
}


bool isEmpty(List* L)
{
    if (L->p_tail == nullptr || L->p_head == nullptr)
    {
        return true;
    }
    return false;
}

bool addHead(List* &L, int data)
{
    if (L == nullptr)//L was deleted before, dont use it if not new
    {
        return false;
    }
    
    NODE* n_node = createNode(data);
    if (n_node == nullptr)
    {
        return false;
    }
    
    if (isEmpty(L) == true)
    {
        L->p_head = L->p_tail = n_node; 
        return true;
    }
    
    n_node->p_next = L->p_head;
    L->p_head = n_node;
    return true;
}

bool addTail(List* &L, int data)
{
    if (L == nullptr)
    {
        return false;
    }
    
    NODE* n_node = createNode(data);
    if (n_node == nullptr)
    {
        return false;
    }
    
    if (L->p_head == nullptr || L->p_tail == nullptr)
    {
        L->p_head = L->p_tail = n_node;
        return true;
    }
    
    L->p_tail->p_next = n_node;
    L->p_tail = n_node;
    return true;
}

void removeHead(List* &L)
{
    if (L == nullptr)
    {
        cout << "\nList is not exist";
        return;
    }
    
    if (L->p_head == L->p_tail)
    {
        delete L->p_head;
        L->p_head = nullptr;
        delete L;
        L = nullptr;
        cout << "\nList is deleted";
        return;
    }
    
    NODE* t_node = L->p_head;
    L->p_head = L->p_head->p_next;
    delete t_node;
    t_node = nullptr;
}

void removeTail(List* &L)
{
    if (L == nullptr)
    {
        cout << "\nList is not exist";
        return;
    }
    
    if (L->p_head == L->p_tail)
    {
        delete L->p_tail;
        L->p_tail = nullptr;
        delete L;
        L = nullptr;
        return;
    }
    
    NODE* t_node = L->p_head;
    for (; t_node->p_next != L->p_tail; t_node = t_node->p_next);
    delete t_node->p_next;
    t_node->p_next = nullptr;
    L->p_tail = t_node;
}

void removeAll(List* &L)
{
    if (L == nullptr)
    {
        return;
    }
    
    NODE* f_node = L->p_head;
    NODE* b_node = L->p_head;
    while (b_node != nullptr)
    {
        f_node = b_node;
        b_node = b_node->p_next;
        delete f_node;
        f_node = nullptr;
    }
    
    delete L;
    L = nullptr;
}

void printList(List* L)
{
    if (L == nullptr)
    {
        cout << "\nList is not exist";
        return;
    }
    
    for (NODE* t_node = L->p_head; t_node != nullptr; t_node = t_node->p_next)
    {
        cout << t_node->key << " ";
    }
}

int countElements(List* L)
{
    if (L == nullptr)
    {
        return -1;
    }
    
    int cnt = 0;
    for (NODE* t_node = L->p_head; t_node != nullptr; t_node = t_node->p_next)
    {
        cnt++;
    }
    return cnt;
}

List* reverseList(List* L)
{
    List* nlist = new List;
    if (nlist == nullptr)
    {
        return nullptr;
    }
    
    for (NODE* t_node = L->p_head; t_node != nullptr; t_node = t_node->p_next)
    {
        addHead(nlist, t_node->key);
    }
    
    return nlist;
}


void removeDuplicate(List* &L)
{
    if (L == nullptr)
    {
        return;
    }
    
    NODE* c_node = L->p_head;
    NODE* f_node = L->p_head;
    NODE* b_node = L->p_head;
    for (; c_node->p_next != L->p_tail; c_node = c_node->p_next)
    {
        f_node = c_node;
        b_node = c_node->p_next;
        while (b_node != nullptr)
        {
            if (b_node == L->p_tail && c_node->key == b_node->key)
            {
                removeTail(L);
                break;
            }
            
            if (c_node->key == b_node->key)
            {
                b_node = b_node->p_next;
                delete f_node->p_next;
                f_node->p_next = b_node;
                continue;
            }
            
            f_node = b_node;
            b_node = b_node->p_next;
        }
    }
}

bool removeElement(List* &L, int key)
{
    NODE* f_node = L->p_head;
    NODE* b_node = L->p_head->p_next;
    while (b_node != nullptr)
    {
        if (b_node == L->p_tail && b_node->key == key)
        {
            removeTail(L);
            break;
        }
        
        if (b_node->key == key)
        {
            b_node = b_node->p_next;
            delete f_node->p_next;
            f_node->p_next = b_node;
            continue;
        }
        
        f_node = b_node;
        b_node = b_node->p_next;
    }
    
    if (L->p_head->key == key)
    {
        removeHead(L);
    }
    return true;
}








int main()
{
    cout << "\nMODE TABLE:";
    cout << "\n0. End ";
    cout << "\n1. Create node";
    cout << "\n2. Create list with node";
    cout << "\n3. Add node at head";
    cout << "\n4. Add node at tail";
    cout << "\n5. Remove node at head";
    cout << "\n6. Remove node at tail";
    cout << "\n7. Remove list";
    cout << "\n8. Print list";
    cout << "\n9. Count elements of list";
    cout << "\n10. Create a Reversed list";
    cout << "\n11. Remove duplicate node";
    cout << "\n12. Remove key node";
    
    int mode = 0;
    int data = 0;
   
    cout << "\nNode's key: ";
    cin >> data;
    NODE* origin_node = createNode(data);
    
    List* L = createList(origin_node);
    
    while (true)
    {
        if (L == nullptr)
        {
            cout << "\nList is deleted";
            break;
        }
        
        cout << "\nChoose mode: ";
        cin >> mode;
        if (mode == -1)
        {
            break;
        }
        
        else if (mode == 3)
        {
            cout << "\nkey: ";
            cin >> data;
            addHead(L, data);
        }
        
        else if (mode == 4)
        {
            cout << "\nkey: ";
            cin >> data;
            addTail(L, data);
        }
        
        else if (mode == 5)
        {
            removeHead(L);
        }
        
        else if (mode == 6)
        {
            removeTail(L);
        }
        
        else if (mode == 7)
        {
            removeAll(L);
        }
        
        else if (mode == 8)
        {
            cout << "\nYour list: ";
            printList(L);
            cout << endl;
        }
        
        else if (mode == 9)
        {
            cout << "\nNumber of elements: " << countElements(L) << endl;
        }
        
        else if (mode == 10)
        {
            cout << "\nYour reversed List: ";
            printList(reverseList(L));
            cout << endl;
        }
        
        else if (mode == 11)
        {
            removeDuplicate(L);
        }
        
        else if (mode == 12)
        {
            cout << "\nkey: ";
            int key = 0;
            cin >> key;
            cout << removeElement(L, key);
        }
    }

    return 0;
}
