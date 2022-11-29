
#include <iostream>
#include <cstdlib>
using namespace std;
//CODE CHAY DUOC TRONG VISUAL STUDIO 
struct NODE {
    NODE* LLINK;
    NODE* RLINK;
    char INFO1;
    char INFO2;
    int LTAG, RTAG;
};
struct NODESTACK {
    NODE* HEAD;
    NODESTACK* Next;
};
struct STACK {
    NODESTACK* Top;
};
void InitStack(STACK& s) {
    s.Top = nullptr;
}
bool IsEmty(STACK s) {
    if (s.Top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
void Pop(STACK& s) {
    NODESTACK* prt = s.Top;
    s.Top = s.Top->Next;
    delete(prt);
}
NODESTACK* Peek(STACK s) {
    return s.Top;
}
void Push(STACK& s, NODE* x) {
    NODESTACK* ptr = new NODESTACK();
    ptr->HEAD = x;
    ptr->Next = s.Top;
    s.Top = ptr;
}
struct UnThreadedBinaryTree {
    NODE* T;
    void Init() {
        T = nullptr;
    }
    void inorder() {
        STACK A;
        InitStack(A);
        NODE* P = this->T;
        while (IsEmty(A) == false || P != nullptr)
        {
            if (P != nullptr) {
                Push(A, P);
                P = P->LLINK;
            }
            else {
                P = Peek(A)->HEAD;
                Pop(A);
                cout << P->INFO1 << P->INFO2 << " ";
                P = P->RLINK;
            }
        }
    }
    void preoder() {
        STACK A;
        InitStack(A);
        NODE* P = this->T;
        while (IsEmty(A) == false || P != nullptr)
        {
            if (P != nullptr) {
                Push(A, P);
                cout << Peek(A)->HEAD->INFO1 << Peek(A)->HEAD->INFO2 << " ";
                P = P->LLINK;
            }
            else {
                P = Peek(A)->HEAD;
                Pop(A);
                P = P->RLINK;
            }
        }
    }
    void postoder() {
        STACK A;
        InitStack(A);
        NODE* P = this->T;
        NODE* Prev = nullptr;
        while (IsEmty(A) == false || P != nullptr)
        {
            if (P != nullptr) {
                Push(A, P);
                P = P->LLINK;
            }
            else {
                P = Peek(A)->HEAD;
                if (P->RLINK == nullptr || P->RLINK == Prev) {
                    cout << P->INFO1 << P->INFO2 << " ";
                    Pop(A);
                    Prev = P;
                    P = nullptr;
                }
                else {
                    P = P->RLINK;
                }

            }
        }
    }
};
UnThreadedBinaryTree* bulid_unthread_tree() {
    UnThreadedBinaryTree* tree;
    tree = (UnThreadedBinaryTree*)malloc(sizeof(UnThreadedBinaryTree));
    NODE* a = (NODE*)malloc(sizeof(a));
    NODE* b = (NODE*)malloc(sizeof(b));
    NODE* c = (NODE*)malloc(sizeof(c));
    NODE* d = (NODE*)malloc(sizeof(d));
    NODE* e = (NODE*)malloc(sizeof(e));
    NODE* f = (NODE*)malloc(sizeof(f));
    NODE* g = (NODE*)malloc(sizeof(g));
    NODE* h = (NODE*)malloc(sizeof(h));
    NODE* j = (NODE*)malloc(sizeof(j));
    a->INFO1 = '8';
    a->INFO2 = '\0';
    b->INFO1 = '3';
    b->INFO2 = '\0';
    c->INFO1 = '1';
    c->INFO2 = '0';
    d->INFO1 = '1';
    d->INFO2 = '\0';
    e->INFO1 = '6';
    e->INFO2 = '\0';
    f->INFO1 = '4';
    f->INFO2 = '\0';
    g->INFO1 = '7';
    g->INFO2 = '\0';
    h->INFO1 = '1';
    h->INFO2 = '4';
    j->INFO1 = '1';
    j->INFO2 = '3';
    a->LLINK = b;
    a->RLINK = c;
    b->LLINK = d;
    b->RLINK = e;
    c->LLINK = nullptr;
    c->RLINK = h;
    d->LLINK = nullptr;
    d->RLINK = nullptr;
    e->LLINK = f;
    e->RLINK = g;
    f->LLINK = nullptr;
    f->RLINK = nullptr;
    h->LLINK = j;
    h->RLINK = nullptr;
    j->LLINK = nullptr;
    j->RLINK = nullptr;
    g->LLINK = nullptr;
    g->RLINK = nullptr;
    tree->T = a;
    return tree;
}
struct ThreadedBinaryTree {
    NODE* T;
    void Init() {
        T = nullptr;
    }
    NODE* nextNodeInoder(NODE* P) {
        NODE* Q = P->RLINK;
        if (P->RTAG == 1) {
            return Q;
        }
        while (Q->LTAG == 0) {
            Q = Q->LLINK;
        }
        return Q;
    }
    NODE* leftNode(NODE* T) {
        NODE* Q = T->LLINK;
        while (Q->LTAG != 1) {
            Q = Q->LLINK;
        }
        return Q;
    }
    void inorder() {
        NODE* P = leftNode(T);
        while (P != T) {
            cout << P->INFO1 << P->INFO2 << " ";
            P = nextNodeInoder(P);
        }
    }
    void preorder() {
        NODE* P = T->LLINK;
        while (P != T) {
            cout << P->INFO1 << P->INFO2 << " ";
            if (P->LTAG == 0) {
                P = P->LLINK;
            }
            else {
                if (P->RTAG == 1) {
                    P = P->RLINK;
                }
                else {
                    P = P->RLINK;
                }
            }
        }
    }
    void postorder() {
        cout << "CHUA LAM DUOC !";
    }
};
ThreadedBinaryTree* build_thread_tree_inoder() {
    ThreadedBinaryTree* tree;
    tree = (ThreadedBinaryTree*)malloc(sizeof(ThreadedBinaryTree));
    NODE* a = (NODE*)malloc(sizeof(a));
    NODE* b = (NODE*)malloc(sizeof(b));
    NODE* c = (NODE*)malloc(sizeof(c));
    NODE* d = (NODE*)malloc(sizeof(d));
    NODE* e = (NODE*)malloc(sizeof(e));
    NODE* f = (NODE*)malloc(sizeof(f));
    NODE* g = (NODE*)malloc(sizeof(g));
    NODE* h = (NODE*)malloc(sizeof(h));
    NODE* j = (NODE*)malloc(sizeof(j));
    a->INFO1 = '8';
    a->INFO2 = '\0';
    b->INFO1 = '3';
    b->INFO2 = '\0';
    c->INFO1 = '1';
    c->INFO2 = '0';
    d->INFO1 = '1';
    d->INFO2 = '\0';
    e->INFO1 = '6';
    e->INFO2 = '\0';
    f->INFO1 = '4';
    f->INFO2 = '\0';
    g->INFO1 = '7';
    g->INFO2 = '\0';
    h->INFO1 = '1';
    h->INFO2 = '4';
    j->INFO1 = '1';
    j->INFO2 = '3';
    tree->T = (NODE*)malloc(sizeof(tree));
    a->LTAG = 0;  a->RTAG = 0;
    a->LLINK = b; a->RLINK = c;
    b->LTAG = 0;  b->RTAG = 0;
    b->LLINK = d; b->RLINK = e;
    c->LTAG = 1;  c->RTAG = 0;
    c->LLINK = a; c->RLINK = h;
    d->LTAG = 1;  d->RTAG = 1;
    d->LLINK = tree->T; d->RLINK = b;
    e->LTAG = 0;  e->RTAG = 0;
    e->LLINK = f; e->RLINK = g;
    f->LTAG = 1;  f->RTAG = 1;
    f->LLINK = b; f->RLINK = e;
    g->LTAG = 1;  g->RTAG = 1;
    g->LLINK = e; g->RLINK = a;
    h->LTAG = 0;  h->RTAG = 1;
    h->LLINK = j; h->RLINK = tree->T;
    j->LTAG = 1;  j->RTAG = 1;
    j->LLINK = c; j->RLINK = h;
    tree->T->LTAG = 0;
    tree->T->RTAG = 1;
    tree->T->LLINK = a;
    tree->T->RLINK = tree->T;
    return tree;

}
ThreadedBinaryTree* build_thread_tree_preoder() {
    ThreadedBinaryTree* tree;
    tree = (ThreadedBinaryTree*)malloc(sizeof(ThreadedBinaryTree));
    NODE* a = (NODE*)malloc(sizeof(a));
    NODE* b = (NODE*)malloc(sizeof(b));
    NODE* c = (NODE*)malloc(sizeof(c));
    NODE* d = (NODE*)malloc(sizeof(d));
    NODE* e = (NODE*)malloc(sizeof(e));
    NODE* f = (NODE*)malloc(sizeof(f));
    NODE* g = (NODE*)malloc(sizeof(g));
    NODE* h = (NODE*)malloc(sizeof(h));
    NODE* j = (NODE*)malloc(sizeof(j));
    a->INFO1 = '8';
    a->INFO2 = '\0';
    b->INFO1 = '3';
    b->INFO2 = '\0';
    c->INFO1 = '1';
    c->INFO2 = '0';
    d->INFO1 = '1';
    d->INFO2 = '\0';
    e->INFO1 = '6';
    e->INFO2 = '\0';
    f->INFO1 = '4';
    f->INFO2 = '\0';
    g->INFO1 = '7';
    g->INFO2 = '\0';
    h->INFO1 = '1';
    h->INFO2 = '4';
    j->INFO1 = '1';
    j->INFO2 = '3';
    tree->T = (NODE*)malloc(sizeof(tree));
    a->LTAG = 0;  a->RTAG = 0;
    a->LLINK = b; a->RLINK = c;
    b->LTAG = 0;  b->RTAG = 0;
    b->LLINK = d; b->RLINK = e;
    c->LTAG = 1;  c->RTAG = 0;
    c->LLINK = g; c->RLINK = h;
    d->LTAG = 1;  d->RTAG = 1;
    d->LLINK = b; d->RLINK = e;
    e->LTAG = 0;  e->RTAG = 0;
    e->LLINK = f; e->RLINK = g;
    f->LTAG = 1;  f->RTAG = 1;
    f->LLINK = e; f->RLINK = g;
    g->LTAG = 1;  g->RTAG = 1;
    g->LLINK = f; g->RLINK = c;
    h->LTAG = 0;  h->RTAG = 1;
    h->LLINK = j; h->RLINK = j;
    j->LTAG = 1;  j->RTAG = 1;
    j->LLINK = h; j->RLINK = tree->T;
    tree->T->LTAG = 0;
    tree->T->RTAG = 1;
    tree->T->LLINK = a;
    tree->T->RLINK = tree->T;
    return tree;
}
ThreadedBinaryTree* build_thread_tree_postoder() {
    ThreadedBinaryTree* tree;
    tree = (ThreadedBinaryTree*)malloc(sizeof(ThreadedBinaryTree));
    NODE* a = (NODE*)malloc(sizeof(a));
    NODE* b = (NODE*)malloc(sizeof(b));
    NODE* c = (NODE*)malloc(sizeof(c));
    NODE* d = (NODE*)malloc(sizeof(d));
    NODE* e = (NODE*)malloc(sizeof(e));
    NODE* f = (NODE*)malloc(sizeof(f));
    NODE* g = (NODE*)malloc(sizeof(g));
    NODE* h = (NODE*)malloc(sizeof(h));
    NODE* j = (NODE*)malloc(sizeof(j));
    a->INFO1 = '8';
    a->INFO2 = '\0';
    b->INFO1 = '3';
    b->INFO2 = '\0';
    c->INFO1 = '1';
    c->INFO2 = '0';
    d->INFO1 = '1';
    d->INFO2 = '\0';
    e->INFO1 = '6';
    e->INFO2 = '\0';
    f->INFO1 = '4';
    f->INFO2 = '\0';
    g->INFO1 = '7';
    g->INFO2 = '\0';
    h->INFO1 = '1';
    h->INFO2 = '4';
    j->INFO1 = '1';
    j->INFO2 = '3';
    tree->T = (NODE*)malloc(sizeof(tree));
    a->LTAG = 0;  a->RTAG = 0;
    a->LLINK = b; a->RLINK = c;
    b->LTAG = 0;  b->RTAG = 0;
    b->LLINK = d; b->RLINK = e;
    c->LTAG = 1;  c->RTAG = 0;
    c->LLINK = h; c->RLINK = h;
    d->LTAG = 1;  d->RTAG = 1;
    d->LLINK = tree->T; d->RLINK = f;
    e->LTAG = 0;  e->RTAG = 0;
    e->LLINK = f; e->RLINK = g;
    f->LTAG = 1;  f->RTAG = 1;
    f->LLINK = d; f->RLINK = g;
    g->LTAG = 1;  g->RTAG = 1;
    g->LLINK = f; g->RLINK = e;
    h->LTAG = 0;  h->RTAG = 1;
    h->LLINK = j; h->RLINK = c;
    j->LTAG = 1;  j->RTAG = 1;
    j->LLINK = b; j->RLINK = h;
    tree->T->LTAG = 0;
    tree->T->RTAG = 1;
    tree->T->LLINK = a;
    tree->T->RLINK = tree->T;
    return tree;
}
int main()
{
    /* 8
      / \
     3   10
    / \    \
   1  6     14
     / \    /
    4   7  13  */
    UnThreadedBinaryTree* tree1 = bulid_unthread_tree();
    cout << "*UnThreaded Binary Tree: " << endl;
    cout << "Preoder: ";
    tree1->preoder();
    cout << endl;
    cout << "Indorder: ";
    tree1->inorder();
    cout << endl;
    cout << "Postoder: ";
    tree1->postoder();
    cout << endl;
    cout << endl;

    ThreadedBinaryTree* tree2 = build_thread_tree_inoder();
    ThreadedBinaryTree* tree3 = build_thread_tree_preoder();
    ThreadedBinaryTree* tree4 = build_thread_tree_postoder();
    cout << "Threaded Binary Tree:" << endl;
    cout << "Preorder: ";
    tree3->preorder();
    cout << endl;
    cout << "Inorder: ";
    tree2->inorder();
    cout << endl;
    cout << "Postorder: ";
    tree4->postorder();
}
