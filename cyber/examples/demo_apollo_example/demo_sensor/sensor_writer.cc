#include <chrono>
#include <thread>

#include "cyber/cyber.h"
#include "cyber/examples/proto/examples.pb.h"

int main(int argc, char** argv) {
  apollo::cyber::Init(argv[0]);

  auto node = apollo::cyber::CreateNode("demo_sensor_writer");
  auto writer = node->CreateWriter<apollo::cyber::examples::proto::Driver>("/demo/sensor/driver");
  uint64_t seq = 0;

  while (apollo::cyber::OK()) {
    auto msg = std::make_shared<apollo::cyber::examples::proto::Driver>();
    msg->set_msg_id(static_cast<int>(seq));

    AINFO << "[sensor_writer] publish /demo/sensor/driver msg_id=" << msg->msg_id();

    writer->Write(msg);
    ++seq;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // 10 Hz
  }

  apollo::cyber::IsShutdown();
  return 0;
}
