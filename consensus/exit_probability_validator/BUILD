cc_library(
    name = "exit_probability_validator",
    srcs = ["exit_probability_validator.c"],
    hdrs = ["exit_probability_validator.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//common:errors",
        "//common/trinary:trit_array",
        "//consensus:model",
        "//consensus/entry_point_selector",
        "//consensus/ledger_validator",
        "//consensus/tangle",
        "//utils:hash_containers",
        "//utils:logger_helper",
        "@com_github_uthash//:uthash",
    ],
)
