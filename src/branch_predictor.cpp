#include "branch_predictor.hpp"

branch_predictor::branch_predictor(unsigned int t): n_bits(t)
{
    max = (1<<n_bits)-1;
    state = 0;
    Npredictions = 0;
    Nhits = 0;
}

bool branch_predictor::predict()
{
    Npredictions++;
    return state&(1<<(n_bits-1));
}

void branch_predictor::update_state(bool taken, bool hit)
{
    Nhits += hit;

    if(taken)
    {
        state = ++state>max?max:state; 
    }
    else if(state)
    {
        state = --state<0?0:state;
    }
}

float branch_predictor::get_predictor_hit_rate() {
    return (float) Nhits / (float) Npredictions * 100;
}
