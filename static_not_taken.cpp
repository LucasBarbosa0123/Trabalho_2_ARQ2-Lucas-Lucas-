#include "static_not_taken.hpp"

static_not_taken::static_not_taken(){
    Npredictions = 0;
    Nhits = 0;
}

bool static_not_taken::predict(){
    Npredictions ++;
    return false;
}

void static_not_taken::update_state(bool hit){
    Nhits += hit;
}

float static_not_taken::get_predictor_hit_rate() {
    return (float) Nhits / (float) Npredictions * 100;
}
