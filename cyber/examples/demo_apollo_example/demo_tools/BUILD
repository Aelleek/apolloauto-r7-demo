load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])


# Perception Logger Component .so
cc_library(
    name = "demo_perception_logger_component_lib",
    srcs = ["demo_perception_logger_component.cc"],
    hdrs = ["demo_perception_logger_component.h"],
    deps = [
        "//cyber",
        "//modules/perception/proto:perception_obstacle_cc_proto",
    ],
)

cc_binary(
    name = "libdemo_perception_logger_component.so",
    linkshared = True,
    linkstatic = False,
    deps = [":demo_perception_logger_component_lib"],
)

cpplint()