load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])


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


cpplint()