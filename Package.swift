// swift-tools-version: 5.10
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "ios-analysis-pod",
    platforms: [.iOS(.v14)],
    products: [
        .library(
            name: "ios-analysis-pod",
            targets: ["ios-analysis-pod"]),
    ],
    targets: [
        .target(
            name: "ios-analysis-pod"),
        .binaryTarget(name: "PoilabsAnalysis",
                      path: "PoilabsAnalysis.xcframework"),
        .testTarget(
            name: "ios-analysis-podTests",
            dependencies: ["ios-analysis-pod"]),
    ],
    swiftLanguageVersions: [.v5]
)
