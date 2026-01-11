#include "demo_perception_logger_component.h"

bool DemoPerceptionLogger::Init(){

    AINFO << "Demo Perception Logger Component init";
    
    return true;
}

bool DemoPerceptionLogger::Proc(const std::shared_ptr<apollo::perception::PerceptionObstacles>& msg0){
    
    if(!msg0){
        AERROR << "DemoPerceptionLogger Received null Perceptionobstacles";
        return false;
    }

    AINFO << "[logger] module=" << msg0->header().module_name()
        << " ts=" << msg0->header().timestamp_sec()
        << " obstacle_size=" << msg0->perception_obstacle_size();

    return true;
    
}