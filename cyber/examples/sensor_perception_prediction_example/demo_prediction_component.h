#include <memory>

#include "cyber/component/component.h"
#include "modules/perception/proto/perception_obstacle.pb.h"
#include "modules/prediction/proto/prediction_obstacle.pb.h"

class DemoPredictionComponent : public apollo::cyber::Component<apollo::perception::PerceptionObstacles>{
    public:
    bool Init() override;
    bool Proc(const std::shared_ptr<apollo::perception::PerceptionObstacles>& msg0) override;

    private:
    std::shared_ptr<apollo::cyber::Writer<apollo::prediction::PredictionObstacles>> writer_;
};
CYBER_REGISTER_COMPONENT(DemoPredictionComponent)
