# PoilabsAnalysis

[![Version](https://img.shields.io/cocoapods/v/PoilabsAnalysis.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)
[![Platform](https://img.shields.io/cocoapods/p/PoilabsAnalysis.svg?style=flat)](https://cocoapods.org/pods/PoilabsNavigation)

## INSTALLATION

### CocoaPods

To integrate PoilabsNavigation into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
pod 'PoilabsAnalysis'
```
### Manually
You can add PoilabsAnalysis.xcframework file to your "Frameworks, Libaries, and Embedded Content" in your Project’s General Tab.
## PRE-REQUIREMENTS
To Integrate this framework you should add some features to your project info.plist file.

#### Location Permission
This framework give support both Always and WhenInUse authorization.
 - Privacy - Location Usage Description

 - Privacy - Location When In Use Usage Description

 - Privacy - Location Always Usage Description

- Privacy - Location Always and When In Use Usage Description

#### Required Background Modes

You should add "Location updates" and "Uses Bluetooth LE accessories" Background Modes from Project's Signing & Capabilities tab.

## USAGE

### Swift

You should import framework in your AppDelegate

```swift
import PoilabsAnalysis
```

In applicationDidBecomeActive: method you should activate the framework:

```swift
        PLAnalysisSettings.sharedInstance().applicationId = APPLICATION_ID
        PLAnalysisSettings.sharedInstance().applicationSecret = APPLICATION_SECRET_KEY
        PLAnalysisSettings.sharedInstance().analysisUniqueIdentifier = UNIQUE_ID
        
         PLConfigManager.sharedInstance().getReadyForTracking(completionHandler: { error in
            if error != nil {
                if let anError = error {
                    print("Error Desc \(anError)")
                }
            } else {
                print("Error Nil")
                PLSuspendedAnalysisManager.sharedInstance()?.stopBeaconMonitoring()
                PLStandardAnalysisManager.sharedInstance()?.startBeaconMonitoring()
                PLStandardAnalysisManager.sharedInstance().delegate = self as? PLAnalysisManagerDelegate
            }
        })
```

##### For background tracking:

In didFinishLaunchingWithOptions:  method you should activate the framework:

```swift
    if launchOptions?[UIApplication.LaunchOptionsKey.location] != nil {
        if application.applicationState == UIApplication.State.background {
            PLSuspendedAnalysisManager.sharedInstance()?.startBeaconMonitoring()
        }
    }
```

##### Close All Actions
If you want to close all location services and regions for SDK you can call this method:

```swift
PLAnalysisSettings.sharedInstance()?.closeAllActions()
```
