#include "demo_perception_component.h"

bool DemoPerceptionComponent::Init(){
    AINFO << "Demo Perception component init";
    writer_ = this->node_->CreateWriter<apollo::perception::PerceptionObstacles>("/demo/perception/obstacles");
    return true;
}

bool DemoPerceptionComponent::Proc(const std::shared_ptr<apollo::cyber::examples::proto::Driver>& msg0){

    if(!msg0){
        AERROR << "DemoPerceptionComponent Received null Driver";
        return false;
    }

    auto out = std::make_shared<apollo::perception::PerceptionObstacles>();

    // Header (minimal valid)
    auto* header = out->mutable_header();
    header->set_timestamp_sec(apollo::cyber::Time::Now().ToSecond());
    header->set_module_name("demo_perception_component");

    // One obstacle (minimal valid)
    auto* obs = out->add_perception_obstacle();
    obs->set_id(msg0->msg_id());
    obs->set_type(apollo::perception::PerceptionObstacle::VEHICLE);

    auto* pos = obs->mutable_position();
    pos->set_x(0.0);
    pos->set_y(0.0);
    pos->set_z(0.0);

    AINFO << "[perception] received driver msg_id=" << msg0->msg_id()
        << " -> publish /demo/perception/obstacles obstacle_id=" << obs->id();

    writer_->Write(out);

    return true;
}