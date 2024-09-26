#include "LinkList.h"

LinkList::LinkList()
{
    this->begin = NULL;
    this->end = NULL;
}

LinkList::~LinkList()
{
    node *current = begin;
    node *nextNode;

    while(current != NULL) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

LinkList::LinkList(const LinkList &ll)
{
    if (ll.begin == NULL) {
        begin = end = NULL;
        return;
    }

    begin = new node();
    begin->value = ll.begin->value;
    begin->next = NULL;

    node *currentOld = ll.begin->next;
    node *currentNew = begin;

    while(currentOld != NULL) {
        currentNew->next = new node();
        currentNew = currentNew->next;
        currentNew->value = currentOld->value;

        currentOld = currentOld->next;
    }
    end = currentNew;
    currentNew->next = NULL;
}

// Thêm phần tử x vào cuôi danh sách
void LinkList::addEnd(int val)
{
    node *newNode = new node();
    newNode->value = val;
    if (begin == NULL) {
        // danh sach rong
        begin = newNode;
        end = newNode;
    } else {
        end->next = newNode;
        end = newNode;
    }
}

// Thêm phần tử x vào đầu danh sách
void LinkList::addBegin(int val)
{
    node *newNode = new node();
    newNode->value = val;
    if (begin == NULL) {
        // danh sach rong
        begin = newNode;
        end = newNode;
    } else {
        newNode->next = begin;
        begin = newNode;
    }
}

// Thêm phần tử x vào sau 1 phần tử
void LinkList::addLaterOneElement(int element, int val)
{
    node *newNode = new node();
    newNode->value = val;

    if (begin == NULL) {
        // danh sach rong
        cout << "The linked list is empty. Please add the element. \n";
        return;
    }

    node *current = begin;
    while(current != NULL) {
        if (current->value == element) {
            newNode->next = current->next;
            current->next = newNode;
        }

        if (current == end) {
            end = newNode;
        }
        current = current->next;
    }
}

// Xóa 1 phần tử ở cuối danh sách
void LinkList::deleteEnd()
{
    // danh sach rong
    if (begin == NULL) {
        cout << "The linked list is empty. \n";
        return;
    }

    // danh sach chi co 1 phan tu
    if (begin == end) {
        delete begin;
        begin = end = NULL;
        return;
    }

    // danh sach  co nhieu hon 1 phan tu
    node *current = begin;
    while(current->next != end) {
        current = current->next;
    }

    delete end;
    end = current;
    end->next = NULL;
}

// Xóa phần tử ở đầu danh sách
void LinkList::deleteBegin()
{
    // danh sach rong
    if (begin == NULL) {
        cout << "The linked list is empty. \n";
        return;
    }

    // danh sach co 1 phan tu
    if (begin == end) {
        delete begin;
        begin = end = NULL;
        return;
    }

    node *current = begin;
    begin = current->next;
    delete current;
}

// Xóa phần tử sau 1 phần tử
void LinkList::deleteLaterOneElement(int element)
{
    if (begin == NULL) {
        // danh sach rong
        cout << "The linked list is empty. Please add the element. \n";
        return;
    }

    // danh sach co 1 phan tu
    if (begin == end) {
        cout << "The linked list has only 1 element. \n";
        return;
    }

    // danh sach co nhieu hon 1 phan tu
    node *current = begin;
    while(current != NULL && current->next != NULL) {
        if (current->value == element) {
            node *tmp = current->next;
            if (tmp == NULL) {
                cout << "Khong co phan tu nao phia sau " << element << endl;
                return;
            }
            current->next = tmp->next;
            if (tmp == end) {
                end = current;
            }
            delete tmp;
            return;
        }
        current = current->next;
    }    
    cout << "Khong tim thay phan tu " << element << " trong danh sach. \n";
}

// sắp xếp danh sách tăng dần
void LinkList::sortAscending()
{
    for (node *i = begin; i != NULL; i = i->next) {
        node *min = i;
        for (node *j = (i->next); j != NULL; j = j->next) {
            if (min->value > j->value) {
                min = j;
            }
        }
        // swap
        swap(min->value, i->value);
   }
}

// sắp xếp danh sách giảm dần
void LinkList::sortDescending()
{
    for (node *i = begin; i != NULL; i = i->next) {
        node *min = i;
        for (node *j = (i->next); j != NULL; j = j->next) {
            if (min->value < j->value) {
                min = j;
            }
        }
        // swap
        swap(min->value, i->value);
   }
}

ostream &operator << (ostream &out, const LinkList &L)
{
    node *current = L.begin;
    while(current != NULL) {
        out << current->value << " ";
        current = current->next;
    }
    out << endl;
    return out;
}

// Thêm 1 phần tử có giá trị X trong DSLK
void LinkList::addElementX(int element)
{
    node *current = begin;
    bool found = false;

    while(current != NULL) {
        if (current->value == element) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found == false) {
        cout << "Khong tim gia tri de them. \n";
        return;
    }
    node *newNode = new node();
    newNode->value = element;
    node *tmp = end;
    tmp->next = newNode;
    end = newNode;
}

// Xóa 1 phần tử có giá trị x trong DSLK
void LinkList::deleteElementX(int element)
{
    node *current = begin;
    
    bool found = false;
    while(current->next != NULL) {
        if (current->next->value == element) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found == false) {
        cout << "Khong tim thay gia tri can xoa. \n";
        return;
    }
    // xoa
    node *tmp = current->next;
    current->next = tmp->next;
    delete tmp;
}