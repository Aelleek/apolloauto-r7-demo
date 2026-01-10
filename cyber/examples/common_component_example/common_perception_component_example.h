#include <memory>

#include "cyber/component/component.h"
#include "modules/perception/proto/perception_obstacle.pb.h"

using apollo::cyber::Component;

class CommonPerceptionComponentSample : public Component<apollo::perception::PerceptionObstacles> {
 public:
  bool Init() override;
  bool Proc(const std::shared_ptr<apollo::perception::PerceptionObstacles>& msg0) override;

 private:
 };
CYBER_REGISTER_COMPONENT(CommonPerceptionComponentSample)