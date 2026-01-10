/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include "cyber/examples/common_component_example/common_component_example.h"

using apollo::cyber::examples::proto::Driver;
using apollo::perception::PerceptionObstacles;

bool CommonComponentSample::Init() {
  AINFO << "Commontest component init";
  prediction_writer_ = this->node_->CreateWriter<Driver>("/apollo/prediction");
  perception_writer_ = this->node_->CreateWriter<PerceptionObstacles>("/apollo/perception/obstacles");
  return true;
}


bool CommonComponentSample::Proc(const std::shared_ptr<Driver>& msg0) {
  AINFO << "Start common component Proc [" << msg0->msg_id() << "]" ;

 // prediction(Driver) 흐름 유지 
  auto out = std::make_shared<Driver>();
  out->set_msg_id(msg0->msg_id());
  out->set_timestamp(msg0->timestamp());
  out->set_content("from common_component, src_msg_id=" + std::to_string(msg0->msg_id()));
  
  prediction_writer_->Write(out);
  AINFO << "Publish /apollo/prediction msg_id=" << out->msg_id();


  // 신규 perception 흐름 추가 (PerceptionObstacles)
  auto p_out = std::make_shared<PerceptionObstacles>();

  // header 채우기
  p_out->mutable_header()->set_timestamp_sec(
      apollo::cyber::Time::Now().ToSecond());
  p_out->mutable_header()->set_module_name("common_component_sample");

  // obstacle 1개만 넣어서 확인 가능하게
  auto* obj = p_out->add_perception_obstacle();
  obj->set_id(static_cast<int32_t>(msg0->msg_id()));
  obj->set_type(apollo::perception::PerceptionObstacle::VEHICLE);
  obj->mutable_position()->set_x(0.0);
  obj->mutable_position()->set_y(0.0);
  obj->mutable_position()->set_z(0.0);

  perception_writer_->Write(p_out);
  AINFO << "Publish /apollo/perception/obstacles id=" << obj->id();

  
  return true;
}
