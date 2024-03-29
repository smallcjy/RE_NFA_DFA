#ifndef NFA_CPP
#define NFA_CPP

#include<iostream>
#include"NFA.hpp"
using namespace std;

NFA::NFA(){}

int NFA::get_num_states(){
    return states.size();
}

void NFA::set_state(int num_states){
    for(int i = 0; i < num_states; i++){
        states.push_back(i);
    }
}

void NFA::set_transfer(int n_from, int n_out, char symbol){
    Transfer new_tran;
    new_tran.node_from = n_from;
    new_tran.node_out = n_out;
    new_tran.symbol = symbol;
    Transfers.push_back(new_tran);
}

void NFA::set_final_state(int final){
    final_state = final;
}

int NFA::get_final_state(){
    return final_state;
}

vector<Transfer> NFA::get_tran(){
    return Transfers;
}

void NFA::display(){
    Transfer cur_tran;
    for(int i = 0; i < Transfers.size(); i++){
        cur_tran = Transfers[i];
        cout<<"Node "<<cur_tran.node_from<<" --> Node "<<cur_tran.node_out<<" : Symbol: "<<cur_tran.symbol<<endl;
    }
    cout<<"The final state is Node: "<<get_final_state()<<endl;
}

NFA concat(NFA a, NFA b){
    NFA result;
    result.set_state(a.get_num_states() + b.get_num_states());
    for(vector<Transfer>::iterator it = a.get_tran().begin(); it != a.get_tran().end(); it++){
        result.set_transfer(it->node_from, it->node_out, it->symbol);
    }
    result.set_transfer(a.get_final_state(),a.get_final_state()+1,'^');
    int num_a = a.get_num_states();
    for(vector<Transfer>::iterator it = b.get_tran().begin(); it!= b.get_tran().end(); it++){
        result.set_transfer(it->node_from+num_a, it->node_out+num_a, it->symbol);
    }
    result.set_final_state(a.get_num_states()+b.get_num_states()-1);
}

NFA or_op()
#endif 