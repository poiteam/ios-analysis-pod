// swift-tools-version: 5.10
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "PoilabsAnalysis",
    platforms: [.iOS(.v14)],
    products: [
        .library(
            name: "PoilabsAnalysis",
            targets: ["PoilabsAnalysis"]),
    ],
    targets: [
        .binaryTarget(name: "PoilabsAnalysis",
                      path: "./PoilabsAnalysis.xcframework"),
    ],
    swiftLanguageVersions: [.v5]
)
