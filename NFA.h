#include<vector>
#include<string>
using namespace std;

//Transfer struct
struct Transfer
{
    int node_from;
    int node_out;
    char symbol;
};


//NFA class
class NFA{
    private:
        //非终态
        vector<int> states;
        vector<Transfer> Tranfers;
        int final_state;
    public:
        NFA();
        int get_num_states();
        void set_state(int);
        void set_transfer(int,int,char);
        void set_final_state(int);
        int get_final_state();
        void display();
};

//NFA's construct func
//连接NFA
NFA concat(NFA,NFA);
//或NFA
NFA or_op(vector<NFA> select_NFAs, int no_of_selections);
//闭包NFA
NFA kleene(NFA a);
//RE转NFA
NFA re_to_nfa(void);    //这里用你的树作为输入