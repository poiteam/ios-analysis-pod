//
//  PLLocationManagerSettings.h
//  PoilabsAnalysis
//
//  Created by ERCAN AYYILDIZ on 08/08/2017.
//  Copyright © 2017 poilabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSInteger, PLLocationPermission)
{
    PLLocationPermissionRequestAlwaysAuthorization,
    PLLocationPermissionRequestWhenInUseAuthorization
};


@interface PLLocationManagerSettings : NSObject

-(id) initWithData:(NSDictionary *)data;

@property(assign, nonatomic) BOOL updateLocationForGpsInformation; // defaul no

@property(assign, nonatomic) BOOL updateLocationForBeaconMonitoring; // defaul yes

@property(assign, nonatomic) PLLocationPermission preferredLocationPermission; // defaul always

@property(assign, nonatomic) CLLocationAccuracy preferredDesiredLocationAccuracy; // default 3 km

@property(assign, nonatomic) BOOL pauseBackgroundLocationUpdates; // default no

@property(assign, nonatomic) BOOL startMonitoringSignificantLocationChanges; // default yes

@property(assign, nonatomic) BOOL allowsBackgroundLocationUpdates; // default yes

@end
