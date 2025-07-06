#include "static_taken.hpp"

static_taken::static_taken(){
    Npredictions = 0;
    Nhits = 0;
}

bool static_taken::predict(){
    Npredictions ++;
    return true;
}

void static_taken::update_state(bool hit){
    Nhits += hit;
}

float static_taken::get_predictor_hit_rate() {
    return (float) Nhits / (float) Npredictions * 100;
}
