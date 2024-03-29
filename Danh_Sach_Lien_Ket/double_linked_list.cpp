#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node *prev;
    Node *next;
} * node;
void init(node &phead)
{
    phead = NULL;
}
node createNode(int x)
{
    node p = new Node();
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}
void deleteNode(node &head_ref, node del)
{
    if (head_ref == NULL || del == NULL)
    {
        return;
    }
    if (head_ref == del)
    {
        head_ref = del->next;
    }
    if (del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    if (del->prev != NULL)
    {
        del->prev->next = del->next;
    }
    delete del;
    return;
}
void deleteNodeatpoint(node &phead, int x)
{
    if (phead == NULL || x <= 0)
    {
        return;
    }
    node cur = phead;
    int i;
    for (int i = 1; cur != NULL and i < x; i++)
    {
        cur = cur->next;
    }
    if (cur == NULL)
    {
        return;
    }
    deleteNode(phead, cur);
}
void insertLast(node &phead, int x)
{
    node temp = phead;
    node new_node = createNode(x);
    if (phead == NULL)
    {
        phead = new_node;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}
void insertFirst(node &phead, int x)
{
    node new_node = createNode(x);
    if (phead == NULL)
    {
        phead = new_node;
        return;
    }
    else
    {
        phead->prev = new_node;
        new_node->next = phead;
        phead = new_node;
    }
}
void input(node &phead)
{
    int n;
    cout << "\nMoi nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertLast(phead, x);
    }
}
void display(node phead)
{
    for (node p = phead; p != NULL; p = p->next)
    {
        cout << p->data << " ";
    }
}
int main()
{
    // node phead;
    // init(phead);
    // input(phead);
    // cout << "\nDanh sach so nguyen sau khi nhap: ";
    // display(phead);
    // cout << "\nNhap vi tri cua phan tu can xoa: ";
    // int x;
    // cin >> x;
    // deleteNodeatpoint(phead,x);
    // cout << "\nDanh sach so nguyen sau khi xoa: ";
    // display(phead);
    int tmp = 1 << 2;
    cout << tmp;
    return 0;
}
