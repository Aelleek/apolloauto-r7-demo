load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

# Perception Component .so
cc_library(
    name = "demo_perception_component_lib",
    srcs = ["demo_perception_component.cc",],
    hdrs = ["demo_perception_component.h",],
    deps = [
        "//cyber",
        "//cyber/examples/proto:examples_cc_proto",
        "//modules/perception/proto:perception_obstacle_cc_proto",
    ],
)

cc_binary(
    name = "libdemo_perception_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":demo_perception_component_lib"],
)

# Prediction Component .so
cc_library(
    name = "demo_prediction_component_lib",
    srcs = ["demo_prediction_component.cc"],
    hdrs = ["demo_prediction_component.h"],
    deps = [
        "//cyber",
        "//modules/perception/proto:perception_obstacle_cc_proto",
        "//modules/prediction/proto:prediction_obstacle_cc_proto",
    ],
)

cc_binary(
    name = "libdemo_prediction_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":demo_prediction_component_lib"],
)

cc_binary(
    name = "sensor_writer",
    srcs = ["sensor_writer.cc"],
    deps = [
        "//cyber",
        "//cyber/examples/proto:examples_cc_proto",
    ],
)



cpplint()