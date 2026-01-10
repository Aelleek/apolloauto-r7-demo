#include "common_perception_component_example.h"

bool CommonPerceptionComponentSample::Init() {
  AINFO << "Common Perception component init";
  return true;
}

bool CommonPerceptionComponentSample::Proc(const std::shared_ptr<apollo::perception::PerceptionObstacles>& msg0) {
  
  if (!msg0) {
    AERROR << "Received null PerceptionObstacles";
    return false;
  }
  
  // Header log
  const auto& header = msg0->header();
  AINFO << "PerceptionObstacles received. "
        << "module_name=" << header.module_name()
        << ", timestamp_sec=" << header.timestamp_sec()
        << ", obstacle_size=" << msg0->perception_obstacle_size();

  // Print up to N obstacles to avoid log spam
  const int kMaxPrint = 5;
  const int n = msg0->perception_obstacle_size();
  for (int i = 0; i < n && i < kMaxPrint; ++i) {
    const auto& obs = msg0->perception_obstacle(i);
    AINFO << "  obs[" << i << "]: id=" << obs.id()
          << ", type=" << obs.type()
          << ", pos=(" << obs.position().x()
          << ", " << obs.position().y()
          << ", " << obs.position().z() << ")";
  }

  return true;
}