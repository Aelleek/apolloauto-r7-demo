#include "cyber/examples/common_component_example/common_prediction_component_example.h"

using apollo::cyber::examples::proto::Driver;

bool CommonPredictionComponentSample::Init() {
  AINFO << "Common Prediction component init";
  return true;
}

bool CommonPredictionComponentSample::Proc(const std::shared_ptr<Driver>& msg0) {
  AINFO << "Start common prediction component Proc [" << msg0->msg_id() << "]" ;
  return true;
}
