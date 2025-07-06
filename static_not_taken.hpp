class static_not_taken
{
public:
    static_not_taken();
    bool predict();
    void update_state(bool hit);
    float get_predictor_hit_rate();

private:
    int c_predictions, c_hits;
};