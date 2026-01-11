#include <memory>

#include "cyber/component/component.h"
#include "cyber/examples/proto/examples.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"

class DemoPerceptionComponent : public apollo::cyber::Component<apollo::cyber::examples::proto::Driver>{
    public:
    bool Init() override;
    bool Proc(const std::shared_ptr<apollo::cyber::examples::proto::Driver>& msg0) override;

    private:
    std::shared_ptr<apollo::cyber::Writer<apollo::perception::PerceptionObstacles>> writer_;
};
CYBER_REGISTER_COMPONENT(DemoPerceptionComponent)
