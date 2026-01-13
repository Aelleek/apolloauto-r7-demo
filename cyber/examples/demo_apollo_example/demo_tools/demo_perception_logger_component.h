#include <memory>

#include "cyber/component/component.h"
#include "modules/perception/proto/perception_obstacle.pb.h"

class DemoPerceptionLogger : public apollo::cyber::Component<apollo::perception::PerceptionObstacles>{
    public:
    bool Init() override;
    bool Proc(const std::shared_ptr<apollo::perception::PerceptionObstacles>& msg0) override;

    private:
};
CYBER_REGISTER_COMPONENT(DemoPerceptionLogger)
