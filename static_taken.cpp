#include "static_taken.hpp"

static_taken::static_taken(){
    c_predictions = 0;
    c_hits = 0;
}

bool static_taken::predict(){
    c_predictions ++;
    return true;
}

void static_taken::update_state(bool hit){
    c_hits += hit;
}

float static_taken::get_predictor_hit_rate() {
    return (float) c_hits / (float) c_predictions * 100;
}
