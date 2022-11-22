#include <iostream>
using namespace std;
struct Node;
struct List;
struct Node{
    int val = 0;
    Node* next = nullptr;
    explicit Node(int x):val(x){}
};
void free_node(Node * head){
    Node * run = head;
        while(run->next !=nullptr){
            run = run->next;
            if(head != nullptr)
            delete head;
            head = run;
        }
        delete head;
}
struct List{
    Node * head = nullptr;
    List() =default;
    explicit List(Node * beg):head(beg){};
    void push_back(int val){
        if(head == nullptr) {
            head = new Node(val);
            return;
        }
        Node * runner = head;
        while(runner->next != nullptr)
            runner = runner->next;
        runner->next = new Node(val);
    }
    friend ostream& operator<<(ostream& out, const List& a);
    List* _insert_list(List& a, int b, int c){
        int idx = 0;
        Node * from = head;
        while(idx++ < b - 1) {
            from = from->next;
            if(from == nullptr)
                throw std::runtime_error("eta korotkaya < b\n");
        }
        idx = (idx > 0 ? --idx : 0);
        Node* to = from->next;
        Node * d =to;
        while(idx++ < c- 1){
            to = to->next;
            delete d;
            d = to;
            if(to == nullptr)
                throw std::runtime_error("eta korotkaya < c\n");
        }
        if(from == head)
            head = a.head;
        else
            from->next = a.head;
        Node* run_a = a.head;
        while(run_a->next != nullptr)
            run_a = run_a->next;
        run_a->next = to->next;
        return this;
    }
//    ~List(){
//        Node * run = head;
//        while(run->next !=nullptr){
//            run = run->next;
//            if(head != nullptr)
//            delete head;
//            head = run;
//        }
//        delete head;
//    }
};

// istream& operator >>(istream& in, List& a){
//     int x;
//     while(in>>x){
//         a.push_back(x);
//     }
// }
 ostream& operator <<(ostream& out, const List& a) {
     Node *runner = a.head;
     if (runner == nullptr)
         return out;
     while (runner->next != nullptr) {
         out << runner->val << ' ';
         runner = runner->next;
     }
     out << runner->val;
     return out ;
 }
int main() {
    List a, b;
    int n , m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        a.push_back(tmp );
    }
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }
    int i, j;
    cin >> i >> j ;
    a._insert_list(b, i, j);
    cout << a << '\n';
    free_node(a.head);
    return 0;
}
