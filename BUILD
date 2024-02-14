cc_library(
    name = "car",
    srcs = ["scripts/source_files/car.cpp"],
    hdrs = ["scripts/header_files/car.hpp"],
    includes = ["scripts/header_files/"],
    copts = ["-Werror"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "car_rental",
    srcs = ["scripts/source_files/car_rental.cpp"],
    hdrs = ["scripts/header_files/car_rental.hpp"],
    includes = ["scripts/header_files/"],
    deps = [":car"],
    copts = ["-Werror"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["scripts/source_files/main.cpp"],
    deps = [":car_rental"],
    copts = ["-Werror"],
    visibility = ["//visibility:public"],
)