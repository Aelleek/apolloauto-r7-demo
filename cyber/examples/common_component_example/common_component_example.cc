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

bool CommonComponentSample::Init() {
  AINFO << "Commontest component init";
  prediction_writer_ = this->node_->CreateWriter<Driver>("/apollo/prediction");
  return true;
}

bool CommonComponentSample::Proc(const std::shared_ptr<Driver>& msg0) {
  AINFO << "Start common component Proc [" << msg0->msg_id() << "]" ;

  Driver out;
  out.set_msg_id(msg0->msg_id());
  out.set_timestamp(msg0->timestamp());
  out.set_content("from common_component, src_msgg_id=" + std::to_string(msg0->msg_id()));

  prediction_writer_->Write(out);

  AINFO << "Publish /apoollo/prediction msg_id = " << out.msg_id();
  return true;
}
