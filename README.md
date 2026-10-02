# PoilabsAnalysis

![Version](https://img.shields.io/github/v/tag/poiteam/ios-analysis-pod?label=version)
![Platform](https://img.shields.io/badge/platform-iOS%2012%2B-lightgrey)

## INSTALLATION

PoilabsAnalysis is distributed with Swift Package Manager. CocoaPods is no longer supported; new versions are not published there.

### Swift Package Manager

1. In Xcode, select **File > Add Package Dependencies...**
2. Enter the repository URL: `https://github.com/poiteam/ios-analysis-pod.git`
3. Choose **Exact Version** `3.8.29` and add the **PoilabsAnalysis** product to your app target.

Requires iOS 12.0 or later.

**Migrating from CocoaPods:** remove `pod 'PoilabsAnalysis'` from your `Podfile`, run `pod install` (or `pod deintegrate` if no other pods remain), then add the package as described above. Do not keep the SDK in your `Podfile` while it is added with SPM.

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

#### For background tracking:

In didFinishLaunchingWithOptions:  method you should activate the framework:

```swift
    if launchOptions?[UIApplication.LaunchOptionsKey.location] != nil {
        if application.applicationState == UIApplication.State.background {
            PLSuspendedAnalysisManager.sharedInstance()?.startBeaconMonitoring()
        }
    }
```

#### Close All Actions
If you want to close all location services and regions for SDK you can call this method:

```swift
PLAnalysisSettings.sharedInstance()?.closeAllActions()
```

## TESTING

You can only test PoilabsAnalysis sdk with real device. You can run on simulator but for testing you should **run on a iPhone**.

Some test cases are only for versions **3.8.2 or above**. For better test cases, please update PoilabsAnalysis if you integrated a lower version.

### Initialization

Error of below method should be nil. 

```swift
PLConfigManager.sharedInstance().getReadyForTracking(completionHandler: { error in

})        
```
#### Error descriptions

1. Request failed: forbidden (403)
	* Please check APPLICATION ID and APPLICATION SECRET KEY
2. Your Application id is Unavailable
 * Set **PLAnalysisSettings.sharedInstance().applicationId**
3. Your Application secret is Unavailable
 * Set **PLAnalysisSettings.sharedInstance().applicationSecret**
4. Your Analysis uniqueId is Unavailable
 * Set **PLAnalysisSettings.sharedInstance().analysisUniqueIdentifier**


### Foreground Monitoring

Foreground monitoring means scaning beacon and returning relevant node's id when application is active. If you initilize PoilabsAnalysis sdk with nil error and start beacon monitoring of **PLStandartAnalysisManager**, node ids will return to callback below. 


```swift
extension AppDelegate: PLAnalysisManagerDelegate {
    func analysisManagerResponse(forBeaconMonitoring response: [AnyHashable : Any]!) {
        print(response)
    }
}
```

For getting response, you have to be **nearby of a beacon** with data which are shared by PoiLabs.

Trigger of this callback can take time, please wait for minumun 30 seconds after start monitoring. 

You can see an example of response below.

```json
{
"data": [
    ["nodeid1", "nodeid2", ...],
    ["nodeid1", ...],
    ["nodeid1", ...],
    ...
    ], 
"status": 1
}
```

If you can get a reponse like this, foreground monitoring is successfully integrated.

### Background Monitoring

Background monitoring means scaning beacon when application is killed. 

Before start to test please make sure **always location permission** is given.

To activate background mode, you should kill application and lock the screen. After you show the lock screen or unlock your iPhone, background monitoring will start if you entegrate it, like in the section **USAGE/For background tracking**.

For getting response, you have to be **nearby of a beacon** with data which are shared by PoiLabs.

You can test background monitoring on Console. Open Console application on your Mac. Type **PLAnalysisSdk** to search field. Select your iPhone from Devices section on the left. Press start button.

First you will see start log and then if sdk find any beacon and get its id, you will see response log. Examples of logs are below.

```json
PLAnalysisSdk <PLSuspendedAnalysisManager: 0x...>->SuspendedAnalysisManager startBeaconMonitoring

PLAnalysisSdk <PLSuspendedAnalysisManager: 0x...>->Response {
    data =     ( (  "nodeid1", "nodeid2", ... ),
                ( "nodeid1", ... ),
                ( "nodeid1", ... )
    );
    status = 1;
}
```
If you get these log, background monitoring is successfully integrated.
