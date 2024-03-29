#ifndef NFA_HPP
#define NFA_HPP
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
        vector<Transfer> Transfers;
        int final_state;
    public:
        NFA();
        //得到自动机的状态数量
        int get_num_states();
        //设置自动机的状态数量
        void set_state(int);
        //设置自动机的转换条件
        void set_transfer(int,int,char);
        //设置终止状态
        void set_final_state(int);
        //设置终止状态
        int get_final_state();
        vector<Transfer> get_tran();
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

#endif

