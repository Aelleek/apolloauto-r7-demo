#include "demo_prediction_component.h"

bool DemoPredictionComponent::Init(){
    AINFO << "Demo Prediction component init";
    writer_ = this->node_->CreateWriter<apollo::prediction::PredictionObstacles>("/demo/prediction/obstacles");
    
    return true;
}

bool DemoPredictionComponent::Proc(const std::shared_ptr<apollo::perception::PerceptionObstacles>& msg0){
    
    if(!msg0){
        AERROR << "DemoPredictionComponent Received null Perceptionobstacles";
        return false;
    }

    auto out = std::make_shared<apollo::prediction::PredictionObstacles>();

    // 1) header
    auto* header = out->mutable_header();
    header->CopyFrom(msg0->header());  
    header->set_module_name("demo_prediction_component");  

    // 2) repeated PredictionObstacle 채우기
    const int n = msg0->perception_obstacle_size();
    for (int i = 0; i < n; ++i) {
        const auto& in_obs = msg0->perception_obstacle(i);

        auto* pred = out->add_prediction_obstacle();
        pred->mutable_perception_obstacle()->CopyFrom(in_obs);

        // timestamp: proto 주석상 "GPS time seconds"
        pred->set_timestamp(msg0->header().timestamp_sec());

        // predicted_period: 일단 고정값으로 (예: 5초)
        pred->set_predicted_period(5.0);
    }

    AINFO << "[prediction] received perception obstacle_size=" << n
            << " -> publish /demo/prediction/obstacles";

    writer_->Write(out);
    return true;
    
}