#include <iostream>
#include <string>
#include <fstream>

using namespace std;



struct List{
    string data;
    int key;
    struct List *next;
};


void print_list(List *list){
    List* cur = list;

    while(cur){
        cout << cur->key << " " << cur->data << endl;
        cur = cur->next;
    }
}


// Функция необходимая для формирования линейного списка по заданию
void append(List **list, int key, string data){
    List *cur = *list;

    if(cur == NULL){
        cur = new List;
        cur->next = NULL;
        cur->key = key;
        cur->data = data;
        *list = cur;
    }
    else{
        while(cur->next){
            cur = cur->next;
        }
        cur->next = new List;
        cur->next->next = NULL;
        cur->next->key = key;
        cur->next->data = data;
    }
}




// Наследуемся от линейного списка -> можем добавлять и печатать через функции для линейного списка
struct BidirectionalList: public List{
    List *prev;
};



void create_bidirectional_list(BidirectionalList** b_list, List *list){
    List *cur = list;

    if (*b_list == NULL)
        *b_list = new BidirectionalList;

    List *b_cur = *b_list;
    List *prev_addr = NULL;

    while(cur) {
        b_cur->key = cur->key;
        b_cur->data = cur->data;
        b_cur->next = cur->next;

        ((BidirectionalList*)b_cur)->prev = prev_addr;

        prev_addr = cur;
        b_cur = b_cur->next;
        cur = cur->next;
    }
}


void add_k_el_to_tail(BidirectionalList **b_list, int k, int key, string data){
    List *cur = *b_list;

    while (cur){
        if (cur->next == NULL) {
            for (int i = 0; i < k; ++i) {
                cur->next = new List;
                cur->next->next = NULL;
                cur->next->key = key;
                cur->next->data = data;
                ((BidirectionalList*)cur->next)->prev = cur;
                cur = cur->next;
            }
            return;
        }

        cur = cur->next;
    }
}



void delete_k_el_before(BidirectionalList **b_list, int idx, int k) {
    List *cur = *b_list;
    int i = 0;

    while (cur){
        if (i == idx-1) {
            for (int j = 0; j < k; ++j) {
                if (cur == NULL)
                    return;
                List *time_cur = cur;

                cur = ((BidirectionalList *)cur)->prev;

                if (cur != NULL)
                    cur->next = time_cur->next;

                if (time_cur->next != NULL)
                    ((BidirectionalList *)time_cur->next)->prev = cur;

                delete time_cur;
            }

            return;
        }

        ++i;
        cur = cur->next;
    }
}



int main(){
    List *list = NULL;

    append(&list, 1, "aaaa");
    append(&list, 2, "bbbb");

    print_list(list);
    cout << endl;

    BidirectionalList *b_list = NULL;
    create_bidirectional_list(&b_list, list);
    add_k_el_to_tail(&b_list, 4, 10, "new data");

    print_list(b_list);
    cout << endl;

    delete_k_el_before(&b_list, 4, 2);

    print_list(b_list);
    cout << endl;


    return 0;
}
