#include "static_not_taken.hpp"

static_not_taken::static_not_taken(){
    c_predictions = 0;
    c_hits = 0;
}

bool static_not_taken::predict(){
    c_predictions ++;
    return false;
}

void static_not_taken::update_state(bool hit){
    c_hits += hit;
}

float static_not_taken::get_predictor_hit_rate() {
    return (float) c_hits / (float) c_predictions * 100;
}
