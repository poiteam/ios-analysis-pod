![Poilabs](https://www.poilabs.com/public/img/poi-labs-logo.png)

# PoilabsAnalysis framework

Version: 3.8.0

## INSTALATION

### CocoaPods

To integrate PoilabsNavigation into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
pod 'PoilabsAnalysis'
```
### Manually
You can add PoilabsAnalysis.xcframework file to your "Frameworks, Libaries, and Embedded Content" in your Project’s General Tab.
## INTEGRATION
To Integrate this framework you should add some features to your project info.plist file.

#### Location Permission
This framework give support both Always and WhenInUse authorization.
 - Privacy - Location Usage Description

 - Privacy - Location When In Use Usage Description

 - Privacy - Location Always Usage Description

- Privacy - Location Always and When In Use Usage Description

#### Required Background Modes

You should add "Location updates" and "Uses Bluetooth LE accessories" Background Modes from Project's Signing & Capabilities tab.

## USSAGE


You should have some information to use this framework:

1. ApplicationId : It should be given by PoiLabs
2. ApplicationSecret : It should be given by PoiLabs
3. AnalysisUniqueIdentifier : It should be defined by you, to identify your customer for us, it is like userId or userEmail.

### Objective-C
You should import framework in your AppDelegate

```objective-c
#import <PoilabsAnalysis/PoilabsAnalysis.h>
```

In applicationDidBecomeActive: method you should activate the framework:

```objective-c
    [[PLAnalysisSettings sharedInstance] setApplicationId:@"applicationId"];
    [[PLAnalysisSettings sharedInstance] setApplicationSecret:@"applicationSecret"];
    [[PLAnalysisSettings sharedInstance] setAnalysisUniqueIdentifier:@"uniqueIdentifier"];
        [[PLConfigManager sharedInstance] getReadyForTrackingWithCompletionHandler:^(PLError *error) {
        if (error) {
            NSLog(@"Error Desc %@",error);
        }
        else
        {
            NSLog(@"Error Nil");
            [[PLSuspendedAnalysisManager sharedInstance] stopBeaconMonitoring];
            [[PLStandardAnalysisManager sharedInstance] startBeaconMonitoring];
            [[PLStandardAnalysisManager sharedInstance] setDelegate:self];
        }
    }];
```

##### For background tracking:

In didFinishLaunchingWithOptions:  method you should activate the framework:

```objective-c
    if ([launchOptions objectForKey:UIApplicationLaunchOptionsLocationKey]
        && [UIApplication sharedApplication].applicationState == UIApplicationStateBackground)
    {
        [[PLSuspendedAnalysisManager sharedInstance] startBeaconMonitoring];
    }
    
```

##### Close All Actions
If you want to close all location services and regions for SDK you can call this method:

```objective-c
[[PLAnalysisSettings sharedInstance] closeAllActions];
```

### Swift

You should import framework in your AppDelegate

```swift
import PoilabsAnalysis
```

In applicationDidBecomeActive: method you should activate the framework:

```swift
        PLAnalysisSettings.sharedInstance().applicationId = applicationId
        PLAnalysisSettings.sharedInstance().applicationSecret = applicationSecret
        PLAnalysisSettings.sharedInstance().analysisUniqueIdentifier = uniqueIdentifier
        
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
        PLConfigManager.sharedInstance()?.getReadyForTracking(completionHandler: { (error) in
            if error != nil {
                if application.applicationState == UIApplicationState.background {
                    PLSuspendedAnalysisManager.sharedInstance()?.startBeaconMonitoring()
                }
            }
        })
    }
```

##### Close All Actions
If you want to close all location services and regions for SDK you can call this method:

```swift
PLAnalysisSettings.sharedInstance()?.closeAllActions()
```
